#include"class_trie.h"

trieNode * trie::findMax(trieNode * t) const{//利用递归寻找匹配次数最多的节点，因为统一前缀会有相同的匹配次数，所以需要取取大于等于才能保证获得的是前缀的最后一个字
	//trieNode * maxNode = new trieNode();!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!这里既然不用到新的节点，就可以不用申请空间，只要像下面一样设置成NULL就可以了，这是比较好的习惯。不然浪费了空间，再递归过程中不断申请空间，程序可能就是因为这个出现bad_alloc的。
	//trieNode * temp = new trieNode();
    trieNode * maxNode = NULL;
    int max = 0;
	if( t != NULL){
		if( t->match_times >= max ){//先判断当前节点的匹配次数和当前最大匹配次数
			max = t->match_times;
			maxNode = t;
		}
		if( t->leftchild != NULL){//递归寻找左儿子
            			trieNode *temp = findMax( t->leftchild);//这里只是申请了一个指针的空间
            			if(temp->match_times >= max){
                			max = temp->match_times;
                			maxNode = temp;
            			}
    //      maxNode = temp->match_times >= max ? temp : maxNode;这种写法漏写了max的更新，max和maxNode应该是同步更新的，所以采用上面的这种方法
    //      maxNode = findMax( t->leftchild)->match_times >= max ? findMax( t->leftchild) : maxNode;这是罪不可取的方法，在原来程序申请不必要的空间的基础上，还两次调用递归，更多地浪费了时间，递归的调用越少越好，两词调用可以把第一次调用的结果保存起来，节省空间时间！！！！！！！！！！！！！！！！！！！！！！！！！！！！
		}
		if( NULL != t->nextsiblin){//递归寻找右兄弟
			trieNode *temp = findMax( t->nextsiblin);
            			if( temp->match_times >= max){
                			max = temp->match_times;
                			maxNode = temp;
            			}
		}
	}
	return maxNode;

}

void trie::makeEmpty(trieNode * t){
	if(t != NULL){
		if( t->leftchild != NULL ){//先递归删除左儿子
			makeEmpty( t->leftchild);
		}
		if( NULL != t->nextsiblin){//再递归删除右兄弟
			makeEmpty( t->nextsiblin);
		}
		delete t;//最后删自己
	}
	t = NULL;
}

void trie::print(){//封装私有成员函数print，保护root
	this->print( root);
}

int trie::getMaxMatchtimes(){
	return findMax( root)->match_times;
}

string trie::printMaxPrefix(){
	trieNode * maxNode = findMax( root);
	stack< string > stk;
	string word;
	string ret;
	while( NULL != maxNode){
		stk.push( maxNode->key);
		maxNode = maxNode->parent;
	}
	while( !stk.empty()){
		word = stk.top();
	//	cout << word;
		stk.pop();
		ret += word;
	}
//	cout << "Prefix: " << ret << endl;
	return ret;
}

void trie::print( trieNode * t){
	if( NULL != t){//先打印自己
		cout << t->key << t->match_times ;
		if( t->match_times == 0){ cout << endl;}//树状结构输出
		if( NULL != t->leftchild){//再打印左儿子
			print( t->leftchild);
		}
		if( NULL != t->nextsiblin){//再打印右兄弟
			print( t->nextsiblin);
		}
	}
}

void trie::insert( const string & s){
	if( NULL == root){
		createRoot();
	}
	bool nextsiblinFinallyNull = true;//标记不匹配当前节点时，有多个右兄弟，但都不匹配的情况
	trieNode * ptr = root;
	string word = "";
	string::size_type i = 0;
	while( i < s.length()){
		word = s.substr(i, 3);
		nextsiblinFinallyNull = true;
		if( word != ptr->key && ptr->key == ""){//不匹配当前节点，当前节点为初始化
	//		if( word == "综"){cout << "*1";}
			ptr->depth = ptr == root ? 1 : ptr->parent->depth +1;
			ptr->key = word;
			ptr->match_times = 1;
			if( NULL == ptr->leftchild){
				newLeftchild( ptr);
			}
			ptr = ptr->leftchild;
		}
		else if( word != ptr->key && ptr->key != ""){//不匹配当前节点，当前节点已初始化
	//		if( word == "综"){cout << "*2";}
			if( NULL == ptr->nextsiblin){
				newNextsiblin( ptr, word);
				ptr = ptr->nextsiblin->leftchild;
			}
			else{
				while( NULL != ptr->nextsiblin){//当前节点右兄弟不为空，循环匹配
				//	if( word == "综"){cout << "*3";}
					if( word == ptr->nextsiblin->key){
						//ptr->nextsiblin->depth = ptr == root ? 1 : ptr->nextsiblin->parent->depth +1;
						ptr->nextsiblin->depth = ptr->depth;
						ptr->nextsiblin->match_times ++;
						if( NULL == ptr->nextsiblin->leftchild){
							newLeftchild( ptr->nextsiblin);
						}
						ptr = ptr->nextsiblin->leftchild;
						nextsiblinFinallyNull = false;
						break;
					}
					else{
				//		if( word == "综"){cout << "*4";}
						ptr = ptr->nextsiblin;
//						continue;
					}
				}
//				cout << nextsiblinFinallyNull << word;
				if( NULL == ptr->nextsiblin && nextsiblinFinallyNull){//循环结束还是没有匹配
				//	if( word == "综"){cout << "*5";}
					newNextsiblin( ptr, word);
					ptr = ptr->nextsiblin->leftchild;
				}
			}
		}
		else if( word == ptr->key){//当前节点匹配
//			if( word == "综"){cout << "*6";}
			ptr->depth = ptr == root ? 1 : ptr->parent->depth +1;
			ptr->match_times++;
			if( NULL == ptr->leftchild){
				newLeftchild( ptr);
			}
			ptr = ptr->leftchild;
		}
		else{//其它
			cout << "WTF" << endl;
			break;
		}
		i = i + 3;
	}
}

trie:: ~trie(){//析构函数
	makeEmpty(root);
}

const trie & trie:: operator= ( trie & rhs ){//深拷贝，赋值操作符必须声明为类的成员，所以左操作数隐士绑定this指针，所以只有一个形参，形参一般为const引用，一般返回值是对右操作数的引用
	if( this != &rhs){
		makeEmpty( this->root);
		root = clone( rhs.root );
	}
	return *this;
}

trieNode * trie::clone( trieNode * t) const{//复制节点的左子树，右兄弟树，父亲树
	if( t == NULL)
		return NULL;
	return new trieNode( t->key, t->match_times, t->depth, clone( t->parent), clone( t->leftchild), clone( t->nextsiblin));
}

trie :: trie(const trie & t){//自定义构造函数，实现深拷贝
	this->root = t.root;
}



#include<iostream>
#include<vector>
#include<list>
using namespace std;
//		Sparse Matrices.
//
//This assignment involves implementing a data structure for representing
//sparse matrices. These are matrices of very large dimensions, say 10^8 by
//10^8, but in which the number of non-zero (or in general non-null) entries
//is much smaller than the total number of entries, say about 10^7. Or, even
//better, there is a limit on the maximum number of entries that can occur
//in a row or column, say 10.
//
//You have to implement a template class for such matrices, which allows
//creating matrices with elements of any type. The methods to be implemented
//are as follows:

template<class T>
class node{
public:
	T val;
    int row;
    int column;
    node(int r, int c){
        row = r;
        column =c;
    }
};
template<class T>
class matrix {
    list<list<node<T> > > grid;
    int row_no, col_no, entries_no;
	public:

	matrix(int n,int m){
		row_no=0;
		col_no=0;
		entries_no=0;
	}

// 	Create an n by m matrix with all entries 0 (or in general, the
//   	default value for the template type T). This is the constructor.
//      Assume that n,m will fit in an int variable.

 	~matrix(){} // The destructor, should release all allocated memory.

	matrix (matrix const &M){} //  copy constructor, should create a copy of
				//  the matrix M.

	matrix const & operator=(matrix const &M){

	}

//	The assignment operator.

   	T &  at(int i, int j){
   		entries_no++;

        if(grid.empty()){
            list<node<T> > dummy_row;
            node<T>* dummy_node = new node<T>(i, j);
            dummy_row.push_back(*dummy_node);
            grid.push_back(dummy_row);
            col_no=1;
            return ((grid.front()).front()).val ;
        }
        else{
        	typename list< list<node<T> > >::iterator itr_row = grid.begin();
        	for(;itr_row!=grid.end();itr_row++){
        		if( (*(*itr_row).begin()).row == i){

        			typename list<node <T > >::iterator itr_col = itr_row.begin();
        			for(; itr_col != (*itr_row).end(); itr_col++){
        				if(*itr_col == j)
        					return (*itr_col).val;
        				else if(*itr_col > j){
        					node<T>* dummy_node = new node<T>(i, j);
        					typename list<node<T> >::iterator to_be_return = (*itr_row).insert(itr_col, *dummy_node);
        					return (*to_be_return).val;
        				}
        			}
        			if(itr_col == itr_row.end()){
        				node<T>* dummy_node = new node<T>(i, j);
        				(*itr_row).push_back(*dummy_node);
        				return (*((*itr_row).back())).val;
        			}
        		}

        		else if( (*(*itr_row).begin()).row > i){
        			list<node<T> > dummy_row;
            		node<T>* dummy_node = new node<T>(i, j);
            		dummy_row.push_back(*dummy_node);
                    typename list<list<node<T> > >::iterator to_be_return = grid.insert(itr_row, dummy_row);
            		row_no++;
            		return  (*((*to_be_return ).front())).val;
        		}

        	}
        	if(itr_row==grid.end()){
        		list<node<T> > dummy_row;
            	node<T>* dummy_node = new node<T>(i, j);
            	dummy_row.push_back(*dummy_node);
            	grid.push_back(dummy_row);
            	row_no++;
            	return  ((grid.back()).back()).val;
        	}
        }
    }


//	The at method takes two integers as parameters and returns
//      a reference to the element M_{ij}. If the element does not exist, it
//	is created with a default value.

	T  rowSum(int i){
		typename list<list<node<T> > >::iterator itr_row = grid.begin();
		T sump = new T;
		T sum = *sump;
		for(; itr_row != grid.end(); itr_row++){
			if ((*((*itr_row).front())).row == i){
				typename list<node<T> >::iterator itr_col= (*itr_row).front();
				for(;itr_col != (*itr_row).end() ; itr_col++){
					sum = sum + (*itr_col).val;
				}
				return sum;
			}
		}
	}




//	Returns the sum of entries in ith row. Assume that '+' operator
// 	is defined for the type T. It need not be commutative, so sum is
//	evaluated left to right in a row. However, it can be assumed that
//	adding a 'null' value does not change the sum. Note that there may
//      not be a '-' operator.

	T colSum(int j){

	}

// 	Same for column sum;

	T diaSum(){

	}

// 	Sum of diagonal entries.

	int rows(){}
	int columns(){}
	int entries(){}
};

// 	Returns the number of rows/columns with at least one non-zero entry
//	and also the total number of non-zero entries.



//While you can use STL lists to implement this, it is probably easier if
//you implement it directly. Store a node for each non-zero entry (or each
//entry that has been accessed), with pointers to the node containing the
//next non-zero entry in each row and column. You can keep a list of
//rows/columns containing non-zero entries with a pointer to the first non-zero
//entry in the row/column.
//
//
//IMPORTANT: The time required for each operation should be O(l), where l is
//the number of non-null entries in the matrix, independent of the dimensions.
//You should try to make it as efficient as possible.
//
//You have to only write the class and its methods. The evaluation will be
//by a program that uses this class.
//
//Submit your file as RollNo_6.cpp

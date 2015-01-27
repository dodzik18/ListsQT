#include "node.h"
#include <utility>
 void swap(Node& lhs, Node& rhs)	
 {
	using std::swap;		
	swap(lhs.val, rhs.val);
}

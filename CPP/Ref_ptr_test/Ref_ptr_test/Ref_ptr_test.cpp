#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "RefPtr.h"

using namespace std;
using namespace CAN;

class B { };
class C : public B { };
class D : public C { };

int main()
{
	C* pc = new C;
	B* pb = new B;
	RefPtr<B> m_ref_ptr(pb);
	RefPtr<C> other_ref(m_ref_ptr);
	//RefPtr<B> m_ref_ptr_ptr(m_ref_ptr);

	//int *i = new int[10];
	_CrtDumpMemoryLeaks();
	return 0;
}

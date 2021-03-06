// Math Vec2 test

#include <iostream>
#include <cassert>

using namespace std;

namespace Constants
{
	static struct Null {
	} CAN_NULL;

	static struct True {
		__forceinline operator bool() const { return true; }
	} CAN_TRUE;

	static struct False {
		__forceinline operator bool() const { return false; }
	} CAN_FALSE;

	static struct Emp {
	} CAN_EMP;

	static struct Full {
	} CAN_FULL;
}

static struct Zero
{
	__forceinline operator double() const { return 0.0; }
	__forceinline operator float() const { return 0.0f; }
	__forceinline operator long long() const { return 0; }
	__forceinline operator unsigned long long() const { return 0; }
	__forceinline operator long() const { return 0; }
	__forceinline operator unsigned long() const { return 0; }
	__forceinline operator int() const { return 0; }
	__forceinline operator unsigned int() const { return 0; }
	__forceinline operator short() const { return 0; }
	__forceinline operator unsigned short() const { return 0; }
	__forceinline operator char() const { return 0; }
	__forceinline operator unsigned char() const { return 0; }
} CAN_ZERO;

static struct One
{
	__forceinline operator double() const { return 1.0; }
	__forceinline operator float() const { return 1.0f; }
	__forceinline operator long long() const { return 1; }
	__forceinline operator unsigned long long() const { return 1; }
	__forceinline operator long() const { return 1; }
	__forceinline operator unsigned long() const { return 1; }
	__forceinline operator int() const { return 1; }
	__forceinline operator unsigned int() const { return 1; }
	__forceinline operator short() const { return 1; }
	__forceinline operator unsigned short() const { return 1; }
	__forceinline operator char() const { return 1; }
	__forceinline operator unsigned char() const { return 1; }
} CAN_ONE;
/*
static struct NegInf
{
	__forceinline operator double() const { return -std::numeric_limits<double>::infinity(); }
	__forceinline operator float() const { return -std::numeric_limits<float>::infinity(); }
	__forceinline operator long long() const { return std::numeric_limits<long long>::min(); }
	__forceinline operator unsigned long long() const { return std::numeric_limits<unsigned long long>::min(); }
	__forceinline operator long() const { return std::numeric_limits<long>::min(); }
	__forceinline operator unsigned long() const { return std::numeric_limits<unsigned long>::min(); }
	__forceinline operator int() const { return std::numeric_limits<int>::min(); }
	__forceinline operator unsigned int() const { return std::numeric_limits<unsigned int>::min(); }
	__forceinline operator short() const { return std::numeric_limits<short>::min(); }
	__forceinline operator unsigned short() const { return std::numeric_limits<unsigned short>::min(); }
	__forceinline operator char() const { return std::numeric_limits<char>::min(); }
	__forceinline operator unsigned char() const { return std::numeric_limits<unsigned char>::min(); }

} CAN_NEG_INFINITY;

static struct PosInf
{
	__forceinline operator double() const { return std::numeric_limits<double>::infinity(); }
	__forceinline operator float() const { return std::numeric_limits<float>::infinity(); }
	__forceinline operator long long() const { return std::numeric_limits<long long>::max(); }
	__forceinline operator unsigned long long() const { return std::numeric_limits<unsigned long long>::max(); }
	__forceinline operator long() const { return std::numeric_limits<long>::max(); }
	__forceinline operator unsigned long() const { return std::numeric_limits<unsigned long>::max(); }
	__forceinline operator int() const { return std::numeric_limits<int>::max(); }
	__forceinline operator unsigned int() const { return std::numeric_limits<unsigned int>::max(); }
	__forceinline operator short() const { return std::numeric_limits<short>::max(); }
	__forceinline operator unsigned short() const { return std::numeric_limits<unsigned short>::max(); }
	__forceinline operator char() const { return std::numeric_limits<char>::max(); }
	__forceinline operator unsigned char() const { return std::numeric_limits<unsigned char>::max(); }
} CAN_INFINITY, CAN_POS_INFINITY;
*/


template<unsigned int N, class T>
class Vec
{
public:
	T v[N];

	inline const T& operator [] (const size_t idx) const
	{
		return v[idx];
	}

	inline T& operator [] (const size_t idx)
	{
		return v[idx];
	}
};

template<class T>
class Vec<2, T>
{
public:
	union
	{
		struct { T x; T y; };
		struct { T u; T v; };
	};

public:
	inline Vec() : x(CAN_ZERO), y(CAN_ZERO) {}
	inline Vec(const Vec& vCopyFrom) : x(vCopyFrom.x), y(vCopyFrom.y) {}
	inline Vec(const T& tVal) : x(tVal), y(tVal) {}
	inline Vec(const T& tx, const T& ty) : x(tx), y(ty) {}
	template<class T1>
	inline Vec(const Vec<2, T1>& vConvertFrom)
		: x(T(vConvertFrom.x)), y(T(vConvertFrom.y)) {}
	template<class T1>
	inline Vec& operator = (const Vec<2, T1>& vOther)
	{
		x = T(vOther.x);
		y = T(vOther.y);
		return *this;
	}
	~Vec() {}

	inline T Sum() const { return x + y; }
	inline T Product() const { return x * y; }

	inline const T& operator [] (const size_t idx) const { assert(idx < 2); return (&x)[idx]; }
	inline		 T& operator [] (const size_t idx) { assert(idx < 2); return (&x)[idx]; }

	//----------------------------------------------------------------------------------------------
	// Unary Operators
	//----------------------------------------------------------------------------------------------
	inline Vec operator + () const { return Vec(+x, +y); }
	inline Vec operator - () const { return Vec(-x, -y); }

	//----------------------------------------------------------------------------------------------
	// Binary Operators
	//----------------------------------------------------------------------------------------------
	inline Vec operator + (const Vec& rhs) const { return Vec(x + rhs.x, y + rhs.y); }
	inline Vec operator - (const Vec& rhs) const { return Vec(x - rhs.x, y - rhs.y); }
	inline Vec operator * (const Vec& rhs) const { return Vec(x * rhs.x, y * rhs.y); }
	inline Vec operator * (const T& rhs) const { return Vec(x * rhs, y * rhs); }
	inline Vec operator / (const Vec& rhs) const 
	{ 
		float x_ = this->x / rhs.x;
		float y_ = this->y / rhs.y;		// 1 / 0 : inf
		Vec v = Vec(x_, y_);
		return v; 
	}
	inline Vec operator / (const T& rhs) const { return Vec(x / rhs, y / rhs); }

	//----------------------------------------------------------------------------------------------
	// Assignment Operators
	//----------------------------------------------------------------------------------------------
	inline const Vec& operator += (const Vec& rhs) { x += rhs.x; y += rhs.y; return *this; }
	inline const Vec& operator -= (const Vec& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
	inline const Vec& operator *= (const T& rhs) { x *= rhs; y *= rhs; return *this; }
	inline const Vec& operator /= (const T& rhs) { x /= rhs; y /= rhs; return *this; }
	inline const Vec& operator *= (const Vec& rhs) { x *= rhs.x; y *= rhs.y; return *this; }
	inline const Vec& operator /= (const Vec& rhs) { x /= rhs.x; y /= rhs.y; return *this; }

	//----------------------------------------------------------------------------------------------
	// Comparison Operators
	//----------------------------------------------------------------------------------------------
	inline bool operator == (const Vec& rhs) const { return x == rhs.x && y == rhs.y; }
	inline bool operator != (const Vec& rhs) const { return x != rhs.x || y != rhs.y; }

	static const Vec ZERO;
	static const Vec UNIT_SCALE;
	static const Vec UNIT_X;
	static const Vec UNIT_Y;
	static const Vec UNIT[2];
};

template<class T> const Vec<2, T> Vec<2, T>::ZERO(CAN_ZERO);
template<class T> const Vec<2, T> Vec<2, T>::UNIT_SCALE(CAN_ONE);
template<class T> const Vec<2, T> Vec<2, T>::UNIT_X(CAN_ONE, CAN_ZERO);
template<class T> const Vec<2, T> Vec<2, T>::UNIT_Y(CAN_ZERO, CAN_ONE);
template<class T> const Vec<2, T> Vec<2, T>::UNIT[2] =
{
	Vec<2, T>(CAN_ONE, CAN_ZERO),
	Vec<2, T>(CAN_ZERO, CAN_ONE)
};

//----------------------------------------------------------------------------------------------
// Binary Operators
//----------------------------------------------------------------------------------------------
template<class T> inline Vec<2, T> operator * (const T& lhs, const Vec<2, T>& rhs) { return rhs * lhs; }

//----------------------------------------------------------------------------------------------
// Output Operators
//----------------------------------------------------------------------------------------------
template<typename T> inline std::ostream& operator << (std::ostream& out, const Vec<2, T>& rhs)
{
	return out << "(" << rhs.x << ", " << rhs.y << ")";
}

typedef Vec<2, float>	Vector2;
typedef Vec<2, int>		Vector2i;
typedef Vec<2, bool>	Vector2b;

int main()
{
	Vector2 vec2_zero;
	Vector2 vec2(10, 20);
	Vector2 vec2_10(1, 0);
	Vector2 vec2_equalxy(30);
	Vector2 vec2_copy_1(vec2);
	Vector2 vec2_copy_2(vec2_equalxy);
	Vector2i vec2_i(1, 2);
	Vector2b vec2_b(true, false);
	Vector2 vec2_copy_3(vec2_i);
	Vector2 vec2_copy_4 = vec2;

	cout << "vec2_zero             :  " << vec2_zero << endl;
	cout << "vec2                  :  " << vec2 << endl;
	cout << "vec2_equalxy          :  " << vec2_equalxy << endl;
	cout << "vec2_copy_1           :  " << vec2_copy_1 << endl;
	cout << "vec2_copy_2           :  " << vec2_copy_2 << endl;
	cout << "vec2_i                :  " << vec2_i << endl;
	cout << "vec2_b                :  " << vec2_b << endl;
	cout << "vec2_copy_3           :  " << vec2_copy_3 << endl;
	cout << "vec2[0]               :  " << vec2[0] << endl;
	cout << "vec2[1]               :  " << vec2[1] << endl;
	cout << "vec2_copy_4           :  " << vec2_copy_4 << endl;
	cout << "vec2.Sum()            :  " << vec2.Sum() << endl;
	cout << "vec2.Product()        :  " << vec2.Product() << endl;
	cout << "vec2 + vec2_equalxy   :  " << vec2 + vec2_equalxy << endl;
	cout << "vec2 - vec2_equalxy   :  " << vec2 - vec2_equalxy << endl;
	cout << "vec2 / vec2_equalxy   :  " << vec2 / vec2_equalxy << endl;
	cout << "vec2 * vec2_equalxy   :  " << vec2 * vec2_equalxy << endl;
	cout << "vec2 + vec2_b         :  " << vec2 + vec2_b << endl;
	cout << "vec2 - vec2_b         :  " << vec2 - vec2_b << endl;

	//Vector2 vec2_b_change = vec2_b;
	//cout << "vec2_b_change         :  " << vec2_b_change << endl;

	Vector2 vec2_calc = vec2 / vec2_b;
	cout << "vec2_calc             :  " << vec2_calc     << endl;
	cout << "vec2 / vec2_b         :  " << vec2 / vec2_b << endl;
	cout << "vec2 * vec2_b         :  " << vec2 * vec2_b << endl;
	cout << "vec2 + vec2_i         :  " << vec2 + vec2_i << endl;
	cout << "vec2 - vec2_i         :  " << vec2 - vec2_i << endl;
	cout << "vec2 / vec2_i         :  " << vec2 / vec2_i << endl;
	cout << "vec2 * vec2_i         :  " << vec2 * vec2_i << endl;
	cout << endl << endl;

	cout << "vec2 / vec2_10         :  " << vec2 / vec2_10 << endl;
	/*
	cout << CAN_ZERO.operator double() << endl;
	cout << -std::numeric_limits<float>::infinity() << endl;
	cout << std::numeric_limits<long long>::min() << endl;
	cout << std::numeric_limits<long long>::min() << endl;
	cout << std::numeric_limits<char>::min() << endl;
	cout << std::numeric_limits<unsigned long long>::min() << endl;
	*/
    return 0;
}


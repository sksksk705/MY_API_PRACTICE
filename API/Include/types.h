#pragma once

typedef struct _tagResolution
{
	unsigned int	iW;
	unsigned int	iH;

	_tagResolution() :
		iW(0),
		iH(0)
	{}

	_tagResolution(int x, int y) :
		iW(x),
		iH(y)
	{}
}RESOLUTION, *PRESOLUTION;

typedef struct _tagPosition
{
	float x;
	float y;

	_tagPosition() :
		x(0.f),
		y(0.f)
	{}

	_tagPosition(float _x, float _y) :
		x(_x), y(_y)
	{}

	_tagPosition(const _tagPosition& pos)
	{
		x = pos.x;
		y = pos.y;
	}

	_tagPosition(const POINT& pt)
	{
		x = pt.x;
		y = pt.y;
	}



	void operator = (const _tagPosition& pos)
	{
		x = pos.x;
		y = pos.y;
	}

	void operator = (const POINT& pt)
	{
		x = pt.x;
		y = pt.y;
	}

	void operator = (float f[2])
	{
		x = f[0];
		y = f[1];
	}

	_tagPosition operator+(const _tagPosition pos)	const
	{
		_tagPosition tPos;
		tPos.x = pos.x + x;
		tPos.y = pos.y + y;

		return tPos;
	}

	_tagPosition operator+(const POINT& pos)	const
	{
		_tagPosition tPos;
		tPos.x = pos.x + x;
		tPos.y = pos.y + y;

		return tPos;
	}

	_tagPosition operator+(float f[2])	const
	{
		_tagPosition tPos;
		tPos.x = x + f[0];
		tPos.y = y + f[1];

		return tPos;
	}

	_tagPosition operator+(float f)	const
	{
		_tagPosition tPos;
		tPos.x = x + f;
		tPos.y = x + f;

		return tPos;
	}


	//=========================== -
	_tagPosition operator-(const _tagPosition pos)	const
	{
		_tagPosition tPos;
		tPos.x = x-pos.x  ;
		tPos.y = y-pos.y  ;

		return tPos;
	}

	_tagPosition operator-(const POINT& pos)	const
	{
		_tagPosition tPos;
		tPos.x = x - pos.x;
		tPos.y = y - pos.y;

		return tPos;
	}

	_tagPosition operator-(float f[2])	const
	{
		_tagPosition tPos;
		tPos.x = x - f[0];
		tPos.y = y - f[1];

		return tPos;
	}

	_tagPosition operator-(float f)	const
	{
		_tagPosition tPos;
		tPos.x = x - f;
		tPos.y = x - f;

		return tPos;
	}


	void operator -= (const _tagPosition pos)
	{
		x -= pos.x;
		y -= pos.y;
	}

	//=========================== *
	_tagPosition operator*(const _tagPosition pos)	const
	{
		_tagPosition tPos;
		tPos.x = pos.x * x;
		tPos.y = pos.y * y;

		return tPos;
	}

	_tagPosition operator*(const POINT& pos)	const
	{
		_tagPosition tPos;
		tPos.x = pos.x * x;
		tPos.y = pos.y * y;

		return tPos;
	}

	_tagPosition operator*(float f[2])	const
	{
		_tagPosition tPos;
		tPos.x = x * f[0];
		tPos.y = y * f[1];

		return tPos;
	}

	_tagPosition operator*(float f) const
	{
		_tagPosition tPos;
		tPos.x = x * f;
		tPos.y = x * f;

		return tPos;
	}


	//=========================== /
	_tagPosition operator/(const _tagPosition pos)	const
	{
		_tagPosition tPos;
		tPos.x = pos.x / x;
		tPos.y = pos.y / y;

		return tPos;
	}

	_tagPosition operator/(const POINT& pos)	const
	{
		_tagPosition tPos;
		tPos.x = pos.x / x;
		tPos.y = pos.y / y;

		return tPos;
	}

	_tagPosition operator/(float f[2])	const
	{
		_tagPosition tPos;
		tPos.x = x / f[0];
		tPos.y = y / f[1];

		return tPos;
	}

	_tagPosition operator/(float f)	const
	{
		_tagPosition tPos;
		tPos.x = x / f;
		tPos.y = x / f;

		return tPos;
	}

	void operator += (const _tagPosition& pos)
	{
		x += pos.x;
		y += pos.y;
	}

}POSITION, *PPOSITION, _SIZE, *_PSIZE;

typedef struct _tagRectangle
{
	float l;
	float t;
	float r;
	float b;

	_tagRectangle() :
		l(0.f),
		t(0.f),
		r(0.f),
		b(0.f)
	{}

}RECTANGLE, *PRECTANGLE;


typedef struct _tagSphere
{
	POSITION tCenter;
	float fRadius;

	_tagSphere() :
		tCenter(0.f, 0.f),
		fRadius(0.f)
	{}

}SPHERE,*PSPHERE;
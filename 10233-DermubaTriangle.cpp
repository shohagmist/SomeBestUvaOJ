#include <stdio.h>
#include <math.h>

#define UP 1
#define DOWN 2

typedef long long int64;


double t_x, t_y;

int64 Square64(int64 d)
{
	return d*d;
}

double Squarel(double d)
{
	return d*d;
}

void getCordinates(int64 m)
{
	int64 low, high, mid, level;
	int direction;

	level = (int64) floor(sqrt(m));

		if(level%2 == 1)
		{
			if(m%2 == 1)
				direction = UP;

			else
				direction = DOWN;
		}

		else
		{
			if(m%2 == 1)
				direction = DOWN;

			else
				direction = UP;
		}

		low = Square64(level);
		high = Square64(level + 1) - 1;

		mid = (high + low)/2;

		if(direction == UP)
			t_y = (3*(level + 1) - 1) - 2;

		else
			t_y = (3*(level + 1) - 2) - 2;


		t_x = m - mid;

}

int main()
{
	int64 n, m;
	double m_x, m_y, n_x, n_y;
	double dis, x, y;

	double UNIT_X = 0.5, UNIT_Y = sqrt(3.0)/6.0 ;


	while(scanf("%lld %lld", &n, &m) == 2)
	{
		getCordinates(n);
		n_x = t_x;
		n_y = t_y;

		getCordinates(m);
		m_x = t_x;
		m_y = t_y;

		x =  (double) (n_x - m_x)*UNIT_X;
		y =  (double) (n_y - m_y)*UNIT_Y;

		dis = hypot(x, y);

		printf("%.3lf\n", dis);

	}
	return 0;
}

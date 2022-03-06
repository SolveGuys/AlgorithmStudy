#include <cstdio>
#include <cmath>

int main() 
{
	double x1, y1, r1, x2, y2, r2;
	double answer;
	
	const double pi = std::acos(-1);
	
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
	
	double d = std::sqrt(
		(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
	);

	if (d >= r1 + r2) 
	{
		answer = 0.0;
	}
	else if ( d <= std::abs(r1-r2) ) 
	{
		answer = r1 < r2 ? r1 * r1 * pi : r2 * r2 * pi;
	}
	else 
	{
		double theta1 = 2 * std::acos((r1 * r1 + d * d - r2 * r2) / (2 * d * r1));
		double theta2 = 2 * std::acos((r2 * r2 + d * d - r1 * r1) / (2 * d * r2));
		
		double triangle1 = r1 * r1 * std::sin(theta1) / 2;
		double triangle2 = r2 * r2 * std::sin(theta2) / 2;

		double sector1 = r1 * r1 * (theta1) / 2;
		double sector2 = r2 * r2 * (theta2) / 2;

		answer = (sector1 + sector2) - (triangle1 + triangle2);
	}
    
	printf("%.3lf",answer);
	
	return 0;
}
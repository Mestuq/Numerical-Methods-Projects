// Maciek Pestka 170088
// Damian Szopiński 185394
// Metoda jawna

#include <iostream>
#include <cmath>



int main()
{
	/* u(x,t)
	* ut-uxx=0;
	* u(x,t)=sin(PiX)
	* u(0,t)=0
	* u(1,t)=0
	*/
	float k = 0.0001785, M = 200;
	int n = 10;
	double h = 0.1;
	double s = k / pow(h, 2);
	float* w;
	w = new float[n + 1];
	std::cout << "0, t:0";
	for (int i = 0; i < n + 1; ++i) {
		w[i] = sin(3.14 * i*h);
		std::cout << "\nw[" << i << "]: " << w[i];
	}
	float t = 0;
	double v[11];
	//v = new double[n+1];
	for (int j = 1; j < M; ++j) {
		v[0] = 0;
		v[n] = 0;
		for (int i = 1; i < n; ++i) {
			v[i] = s * w[i - 1] + (1 - (2 * s)) * w[i] + s * w[i + 1];
		}
		t = j * k;
		std::cout << "\nj: "<<j << " t: " << t;
		for (int i = 0; i <= n; ++i) {
			w[i] = v[i];
			std::cout << "\nw[" << i << "]: " << w[i];
		}
	}


	return 0;
}
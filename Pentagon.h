#pragma once
#include"vertex.h"

template<class T>
class Pentagon {
public:
	vertex<T> vertices[5];
	Pentagon() = default;
	Pentagon(std::istream& in);
	void Read(std::istream& in);
	double Area() const;
	void Print(std::ostream& os) const;
	friend std::ostream& operator<< (std::ostream& out, const Pentagon<T>& point);
};


template<class T> 
Pentagon<T>::Pentagon(std::istream& is) {
	for (int i = 0; i < 5; i++) {
		is >> this->vertices[i];
	}
}

	template<class T>
	double Pentagon<T>::Area() const {
		double Area = 0;
		for (int i = 0; i < 5; i++) {
			Area += (vertices[i].x) * (vertices[(i + 1) % 5].y) - (vertices[(i + 1) % 5].x) * (vertices[i].y);
		}
		Area *= 0.5;
		return abs(Area);
	}

	template<class T>
	void Pentagon<T>::Print(std::ostream& os) const  {
		for (int i = 0; i < 5; i++) {
			os << this->vertices[i];
			if (i != 4) {
				os << ',';
			}
		}
		os << std::endl;
	}

	template<class T>
	void Pentagon<T>::Read(std::istream& in) {
		for (int i = 0;i < 5;i++)
			in >> this->vertices[i];
	}

	template<class T>
	std::ostream& operator<<(std::ostream& os, const Pentagon<T>& point) {
		for (int i = 0; i < 5; i++) {
			os << point.vertices[i];
			if (i != 5) {
				os << ',';
			}
		}
	}



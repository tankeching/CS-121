#include "Beverage.h"
#include "CondimentDecorator.h"
#include "DarkRoast.h"
#include "Decaf.h"
#include "Espresso.h"
#include "Houseblend.h"
#include "Milk.h"
#include "Mocha.h"
#include "Soy.h"
#include "Whip.h"

int main(){
	const Beverage& bev = Espresso();

	cout << bev.description() << " = $" << bev.cost() << ", ";

	const Beverage& bev2 = DarkRoast();
	cout << bev2.description() << " = $" << bev2.cost() << ", ";

	Soy s(bev2);
	cout << s;

	Mocha t(s);
	cout << t;

	Whip u(t);
	cout << u;

	cout << Whip(Mocha(Soy(Espresso())));

	return 0;
}
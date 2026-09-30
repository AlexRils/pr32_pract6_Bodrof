// Pract6_Bodroff.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

//Pract6 Bodroff

class Shipment
{

public:
	
	Shipment(std::string sendernew,
		std::string resipientnew,
		std::string trackingNumbernew,
		double weightnew,
		double pricePerKgnew) {


		if (sendernew == "") {

			throw std::invalid_argument("не может быть пустым");
		}

		if (resipientnew == "") {

			throw std::invalid_argument("не может быть пустым");
		}

		if (trackingNumbernew == "") {

			throw std::invalid_argument("не может быть пустым");
		}

		if (weightnew <= 0) {

			throw std::invalid_argument("не может быть меньше единицы");
		}

		if (pricePerKgnew <= 0) {

			throw std::invalid_argument("не может быть меньше единицы");
		}






		sender = sendernew;

		resipient = resipientnew;

		trackingNumber = trackingNumbernew;

		weight = weightnew;

		pricePerKg = pricePerKgnew;



	}


	void SetSenter(std::string sendernew) {

		if (sendernew == "") {

			throw std::invalid_argument("не может быть пустым");
		}

		sender = sendernew;

	}

	void Setresipient(std::string resipientnew) {


		if (resipientnew == "") {

			throw std::invalid_argument("не может быть пустым");
		}

		resipient = resipientnew;

	}

	void SettrackingNumber(std::string trackingNumbernew) {

		if (trackingNumbernew == "") {

			throw std::invalid_argument("не может быть пустым");
		}


		trackingNumber = trackingNumbernew;

	}

	void SetWeight(double weightnew) {

		if (weightnew <= 0) {

			throw std::invalid_argument("не может быть меньше единицы");
		}

		weight = weightnew;

	}

	void SetpricePerKg(double pricePerKgnew) {

		if (pricePerKgnew <= 0) {

			throw std::invalid_argument("не может быть меньше единицы");
		}

		pricePerKg = pricePerKgnew;

	}

	std::string GetSenter() {

		return sender;

	}

	std::string Getresipient() {

		return resipient;

	}

	std::string GettrackingNumber() {

		return trackingNumber;

	}

	double Getweight() {

		return weight;

	}

	double GetpricePerKg() {

		return pricePerKg;

	}

	//printinfo


	void PrintInfo() {


		std::cout << " отправитель - " << sender <<
			"\n получатель - " << resipient <<
			"\n номер отслеживания - " << trackingNumber <<
			"\n вес - " << weight <<
			"\n цена за киолограмм - " << pricePerKg;

	}


	double Price() {

		double rez = weight * pricePerKg;

		return rez;

	}

protected:


	std::string sender;

	std::string resipient;

	std::string trackingNumber;

	double weight;

	double pricePerKg;
	

};



class ExpressShipment : public Shipment {

public:


	ExpressShipment(std::string sender,
		std::string resipient,
		std::string trackingNumber,
		double weight,
		double pricePerKg, int expressPercentnew, int deliveryDaysnew) : Shipment(sender, resipient, trackingNumber, weight, pricePerKg) {


		if (expressPercentnew < 0 || expressPercentnew > 100) {

			throw std::invalid_argument("не может быть больше или равно нулю");
		}

		if (deliveryDaysnew <= 0) {

			throw std::invalid_argument("не может быть меньше 0");
		}

		if (weight > 30) {

			throw std::invalid_argument("не может быть больше 30");

		}



		expressPercent = expressPercentnew;

		deliveryDays = deliveryDaysnew;

	}


	

	void SetExpressPercent(int expressPercentnew) {


		if (expressPercentnew < 0 || expressPercentnew > 100) {

			throw std::invalid_argument("не может быть больше или равно нулю");
		}

		expressPercent = expressPercentnew;

	}

	void SetdeliveryDays(int deliveryDaysnew) {

		if (deliveryDaysnew <= 0) {

			throw std::invalid_argument("не может быть меньше 0");
		}

		deliveryDays = deliveryDaysnew;

	}


	int GetexpressPercent() {

		return expressPercent;

	}

	int GetdeliveryDays() {

		return  deliveryDays;

	}

	// printinfo

	void PrinеInfoExpressShipment() {

		std::cout << "\n Выраженный процент = " << expressPercent << "\n Дни доставки = " << deliveryDays;

	}



	double calculateCost()  {

		double cost = Price();

		double rez = cost * static_cast<double>(expressPercent) / 100;

		return rez + cost;

	}


	double costPerDay() {

		double rez = calculateCost() / static_cast<double>(deliveryDays);

		return rez;

	}

	

	void changeWeight(double weightnew) {

		if (weightnew <= 0) {

			throw std::invalid_argument(" не может быть меньше  0");

		}


		if (weightnew > 30) {

			throw std::invalid_argument(" не может быть больше 30");
		}

		
		SetWeight(weightnew);


	}





protected:


	int expressPercent;

	int deliveryDays;




};



class InsuredShipment : public Shipment {

public:


	InsuredShipment(std::string sender,
		std::string resipient,
		std::string trackingNumber,
		double weight,
		double pricePerKg, double declaredValuenew, int insurancePercentnew) : Shipment(sender, resipient, trackingNumber, weight, pricePerKg) {


		if (declaredValuenew < 0) {

			throw std::invalid_argument("не может быть меньше 0");

		}

		if (insurancePercentnew < 0 || insurancePercentnew > 20) {

			throw std::invalid_argument("вышли за диапозон 0...20");


		}

		declaredValue = declaredValuenew;

		insurancePercent = insurancePercentnew;


	}



	void SetdeclaredValue(double declaredValuenew) {

		if (declaredValuenew < 0) {

			throw std::invalid_argument("не может быть меньше 0");

		}

		declaredValue = declaredValuenew;

	}

	void SetinsurancePercent(int insurancePercentnew) {

		if (insurancePercentnew < 0 || insurancePercentnew > 20) {

			throw std::invalid_argument("вышли за диапозон 0...20");


		}

		insurancePercent = insurancePercentnew;

	}

	double GetdeclaredValue() {

		return declaredValue;
	}


	int GetinsurancePercentnew() {

		return insurancePercent;

	}




	double calculateCost() {

		double cost = Price();

		double insurance = declaredValue * static_cast<double>(insurancePercent) / 100;

		return cost + insurance;
	}

	double insuranceCost() {

		double rez = declaredValue * static_cast<double>(insurancePercent) / 100;

		return rez;

	}

	void changeDeclaredValue(double declaredValuenew) {


		if (declaredValuenew < 0) {

			throw std::invalid_argument("не может быть меньше 0");

		}

		SetdeclaredValue(declaredValuenew);

	}



	void PrintInfoSetdeclaredValue() {


		std::cout << "стоимость = " << declaredValue << "\n процент страхования = " << insurancePercent;

	}



protected:


	double declaredValue;


    int insurancePercent;
};





int main()
{
  
	setlocale(LC_ALL, "Russian");

	std::string sender;

	std::string resipient;

	std::string trackingNumber;

	double weight;

	double pricePerKg;
	//
	int expressPercent;

	int deliveryDays;
	//
	double declaredValue;
	
	int insurancePercent;
	


	std::cout << "введите отправителя:" << std::endl;

	std::cin >> sender;

	std::cout << "введите получателя" << std::endl;

	std::cin >> resipient;

	std::cout << "введите трекир номер:" << std::endl;

	std::cin >> trackingNumber;

	std::cout << "введите вес:" << std::endl;

	std::cin >> weight;

	std::cout << "введите цену за киллограм:" << std::endl;

	std::cin >> pricePerKg;

	std::cout << "введите процент за эксперсс доставку:" << std::endl;

	std::cin >> expressPercent;

	std::cout << "введите кол-во дней доставки:" << std::endl;

	std::cin >> deliveryDays;

	std::cout << "введите стоимость:" << std::endl;

	std::cin >> declaredValue;

	std::cout << "введите процент страхования:" << std::endl;

	std::cin >> insurancePercent;

	try {



     ExpressShipment expressshipmet(sender, resipient, trackingNumber, weight, pricePerKg, expressPercent, deliveryDays);

     InsuredShipment insuredshipment(sender, resipient, trackingNumber, weight, pricePerKg, declaredValue, insurancePercent);

	 std::cout << "Экспресс доставка :\n";

	 expressshipmet.PrintInfo();

	 expressshipmet.PrinеInfoExpressShipment();

	 std::cout << " \n стоимость доставки = " << expressshipmet.calculateCost();

	 std::cout << " \n стоимость в день = " << expressshipmet.costPerDay();


	 insuredshipment.PrintInfo();

	 insuredshipment.PrintInfoSetdeclaredValue();

	 std::cout << " \n общая стоимость со страховкой  = " << insuredshipment.calculateCost();

	 std::cout << " \n стоимость страховки  = " << insuredshipment.calculateCost();


	 std::cout << " \n Сравнение стоимости:";

	 std::cout << " \n стоимость с доставкой = " << expressshipmet.calculateCost() << " / стоимость со страховкой = " << insuredshipment.calculateCost();


	 //Изменение одного поля

	 std::cout << " \n напишите новое значение полю цена за киллограм \n";

	 double newpricePerKg;

	 std::cin >> newpricePerKg;

	 expressshipmet.SetpricePerKg(newpricePerKg);

	 insuredshipment.SetpricePerKg(newpricePerKg);

	 std::cout << " \n Сравнение после изменения поля";


	 std::cout << " \n стоимость с доставкой = " << expressshipmet.calculateCost() << " / стоимость со страховкой = " << insuredshipment.calculateCost();


	 std::cout << " \n Вывод объектов полсе изменения:";

	 std::cout << " \n ,Быстрая доставка:";


	 expressshipmet.PrintInfo();

	 expressshipmet.PrinеInfoExpressShipment();

	 std::cout << " \n страховка:";

	 insuredshipment.PrintInfo();

	 insuredshipment.PrintInfoSetdeclaredValue();

	 // BED ВАРИАНТ


	 std::cout << " \n Плохой вариант, в процессе заполнения объекта введито не правильные значения";



	 std::string sender2;

	 std::string resipient2;

	 std::string trackingNumber2;

	 double weight2;

	 double pricePerKg2;
	 //
	 int expressPercent2;

	 int deliveryDays2;
	 //
	 double declaredValue2;

	 int insurancePercent2;



	 std::cout << "\n введите отправителя:" << std::endl;

	 std::cin >> sender2;

	 std::cout << "\nвведите получателя" << std::endl;

	 std::cin >> resipient2;

	 std::cout << "\nвведите трекир номер:" << std::endl;

	 std::cin >> trackingNumber2;

	 std::cout << "\nвведите вес:" << std::endl;

	 std::cin >> weight2;

	 std::cout << "\nвведите цену за киллограм:" << std::endl;

	 std::cin >> pricePerKg2;

	 std::cout << "\nвведите процент за эксперсс доставку:" << std::endl;

	 std::cin >> expressPercent2;

	 std::cout << "\nвведите кол-во дней доставки:" << std::endl;

	 std::cin >> deliveryDays2;

	 std::cout << "\nвведите стоимость:" << std::endl;

	 std::cin >> declaredValue2;

	 std::cout << "\nвведите процент страхования:" << std::endl;

	 std::cin >> insurancePercent2;

	 ExpressShipment expressshipmet2(sender2, resipient2, trackingNumber2, weight2, pricePerKg2, expressPercent2, deliveryDays2);

	 InsuredShipment insuredshipment2(sender2, resipient2, trackingNumber2, weight2, pricePerKg2, declaredValue2, insurancePercent2);






	}
	catch (const std::invalid_argument& e) {

		std::cout << "ошибка = " << e.what();
	}


	




}



#include<QtWidgets/qapplication.h>
#include<iostream>
#include<QTimer>


class Printer : public QObject
{
	Q_OBJECT
public slots:
	void printFinished()
	{
		std::cout << "finished" << std::endl;
	}
};

int main(int argc,char**argv)
{
	QApplication app(argc,argv);
	QTimer myTimer;
	Printer myPrinter;
	QObject::connect(&myTimer, &QTimer::timeout, &myPrinter, &Printer::printFinished);
	myTimer.start(2000);

	app.exec();
	return 0;
}
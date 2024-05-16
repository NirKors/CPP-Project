prog: Animal.o Chicken.o ChickenFarm.o Cow.o CowFarm.o Farm.o farmMarket.o Market.o Sheep.o SheepFarm.o
	g++ Animal.o Chicken.o ChickenFarm.o Cow.o CowFarm.o Farm.o farmMarket.o Market.o Sheep.o SheepFarm.o -o CPP_FARM

Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp
Chicken.o: Chicken.cpp Chicken.h Animal.h
	g++ -c Chicken.cpp
ChickenFarm.o: ChickenFarm.cpp ChickenFarm.h Farm.h Animal.h Chicken.h
	g++ -c ChickenFarm.cpp
Cow.o: Cow.cpp Cow.h Animal.h
	g++ -c Cow.cpp
CowFarm.o: CowFarm.cpp CowFarm.h Farm.h Animal.h Cow.h
	g++ -c CowFarm.cpp
Farm.o: Farm.cpp Farm.h Animal.h
	g++ -c Farm.cpp
farmMarket.o: farmMarket.cpp Market.h Farm.h Animal.h
	g++ -c farmMarket.cpp
Market.o: Market.cpp Market.h Farm.h Animal.h CowFarm.h ChickenFarm.h SheepFarm.h
	g++ -c Market.cpp
Sheep.o: Sheep.cpp Sheep.h Animal.h
	g++ -c Sheep.cpp
SheepFarm.o: SheepFarm.cpp SheepFarm.h Farm.h Animal.h Sheep.h
	g++ -c SheepFarm.cpp
clean:
	rm -f *.o

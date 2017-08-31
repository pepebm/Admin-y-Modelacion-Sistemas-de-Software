#include <iostream>

class Avion {
public:
	int serie_avion;
	std::string marca_avion;
	Motor* motor;
	Alas* alas;
	std::string modelo_avion;
	Piloto* piloto;
};

class Motor {
public:
	int potencia;
	std::string marca_motor;
	int serie_motor;
};

class Alas {
public:
	int serie_alas;
	std::string marca_alas;
	float hiper;
};

class Piloto {

};

//-----------------

class Builder {
protected:
   Avion* avion;
private:
   Avion* getAvion()
   {
		return avion;
   }	

   void createAvion()
   {
   		avion = new Avion();
   }

   virtual void buildAlas() = 0;
   virtual void buildMotor() = 0;
   virtual void buildSerie_Avion() = 0;
   virtual void buildMarca_Avion() = 0;
   
};

class BoeingBuilder : public Builder {
    void buildAlas()
    {
		Alas* lasAlas = new Alas();
		lasAlas->setMarca("Boeing");
		avion->setAlas(lasAlas);
    }

    void buildMotor()
    {
	  	Motor* elMotor = new Motor();
		elMotor->setMotor(3500);
		avion->setMotor(elMotor);
    }
    
    void buildMarca_Avion()
    {
		avion->setMarca("Boeing");
    }
    
    void buildSerie_Avion()
    {
		avion->setSerie_Avion(1234);
    }
    
    void buildModelo_Avion()
    {
		avion->setModelo_Avion("Boeing 777");
    }
};

class AirbusBuilder : public Builder {
    void buildAlas()
    {
		Alas* lasAlas = new Alas();
		lasAlas->setMarca("Airbus");
		avion->setAlas(lasAlas);
    }

    void buildMotor()
    {
	  	Motor* elMotor = new Motor();
		elMotor->setMotor(2500);
		avion->setMotor(elMotor);
    }
    
    void buildMarca_Avion()
    {
		avion->setMarca_Avion("Airbus");
    }
    
    void buildSerie_Avion()
    {
		avion->setSerie_Avion(4321);
    }
    
    void buildModelo_Avion()
    {
		avion->setModelo_Avion("Airbus 777");
    }
};

//-----------------------------------

class Director {
private:
    Builder* builder;
public:
   void setBuilder(Builder* bd)
   {
		builder = bd;	
   }
  
   Avion* getAvion()
   {
		return builder->getAvion();
   }

   void construct()
   {
		builder->createAvion();
		builder->buildModelo_Avion();
	    builder->buildSerie_Avion();
		builder->buildMarca_Avion();
		builder->buildMotor();
		builder->buildAlas();
   }

};
//
//  Boisson.h
//
//  Created by Martine Bellaiche on 2019-03-05.
//  Copyright © 2019 Martine Bellaiche. All rights reserved.
//

#ifndef BOISSON_h
#define BOISSON_h
#include "Taxable.h"
#include <string>
#include <string_view>
using namespace std;
class Boisson: public Taxable
{
 public:
    Boisson (string_view nom, double prix);
    string_view getNom() const;
    double getPrix () const;
	virtual void setTaxe(double taxe) override;
	virtual double getTaxe() const override;
protected:
    string nom_;
    double prix_;
    double taxe_;
};


#endif /* Boisson_h */

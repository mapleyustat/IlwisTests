#include "kernel.h"
#include "ilwiscontext.h"
#include "testsuite.h"
#include "catalog.h"
#include "raster.h"
#include "ilwisoperation.h"
#include "operationhelpergrid.h"
#include "operationoverloads.h"
#include "rastercalc.h"

REGISTER_TEST(Rastercalc);

Rastercalc::Rastercalc() : IlwisTestCase("Calc", "RasterOperationsTest")
{
}

void Rastercalc::addition() {

    Ilwis::IRasterCoverage map1;
    DOTEST(map1.prepare(makeInputPath("U_1001A.NTF")),"loading erdas imagine file");

      Ilwis::IRasterCoverage cov = map1 + 100.0;
    DOCOMPARE(cov->pix2value(Ilwis::Pixel(0,0)),225.0,"Checking pix(269,339) for expression raster <operator> number");
    DOCOMPARE(cov->pix2value(Ilwis::Pixel(269,339)),139.0,"Checking pix(269,339) for expression raster <operator> number");
    DOCOMPARE(cov->pix2value(Ilwis::Pixel(29,996)),127.0,"Checking pix(29,996) for expression raster <operator> number");
}

void Rastercalc::substract(){
    Ilwis::IRasterCoverage map1;
    DOTEST(map1.prepare(makeInputPath("U_1001A.NTF")),"loading erdas imagine file");

    Ilwis::IRasterCoverage cov = 100.0 - map1;

    DOCOMPARE(cov->pix2value(Ilwis::Pixel(0,0)),-25.0,"Checking pix(269,339) for expression number <operator> raster");

    map1.prepare("small.mpl");
    Ilwis::IRasterCoverage cov4 = map1 + 100;

    map1.prepare("n000302_sub_kenya.mpr");
    Ilwis::IRasterCoverage map2("kenya_2009ndvi_cor_22.mpr");

    Ilwis::IRasterCoverage cov2 = map1 + map2 / 3;

    DOCOMPARE(cov2->pix2value(Ilwis::Pixel(50,50)),148.18,"Checking pix(50,50) for compound expression");

    Ilwis::IRasterCoverage cov3 = sqrt(cov2);

    DOCOMPARE(cov3->pix2value(Ilwis::Pixel(50,50)),12.173,"Checking pix(50,50) for sqrt");


}


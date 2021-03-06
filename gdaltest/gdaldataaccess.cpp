#include "raster.h"
#include "testsuite.h"
#include "table.h"
#include "featurecoverage.h"
#include "feature.h"
#include "featureiterator.h"
#include "catalog.h"
#include "pixeliterator.h"
#include "ilwiscontext.h"
#include "gdaldataaccess.h"

REGISTER_TEST(GdalDataAccess);

GdalDataAccess::GdalDataAccess() : IlwisTestCase("GdalDataAccess", "GdalConnectorTest")
{
}

void GdalDataAccess::tableAccess(){

    Ilwis::ITable tbl1;
    DOTEST(tbl1.prepare(makeInputPath("rainfall.shp")),"loading table from shape");

    DOCOMPARE(tbl1->recordCount(),(unsigned int)13,"check record count");
    DOTEST(tbl1->cell(1,0).toString() == "UMSS", "column test 1");
    DOTEST(tbl1->cell("APRIL",0).toInt() == 36, "column test 2");
    DOTEST(tbl1->cell("JUNE",2).toInt() == 35, "column test 3");
    DOTEST(tbl1->cell("NOVEMBER",4).toInt() == 81, "column test 4");

    DOTEST(tbl1.prepare(makeInputPath("regions.shp")), "Loaded table regions.shp");

    DOTEST(tbl1->cell("REGIONNAME",3).toString() == "Dire Dawa", "column test 5");
    DOTEST(tbl1->cell("COUNT",7).toDouble() == 34.0, "column test 6");
}

void GdalDataAccess::accessingFeatureData() {
    try {
        Ilwis::IFeatureCoverage fc;
        qDebug() << "Features : accessing data ";

        DOTEST(fc.prepare(makeInputPath("regions.shp")), "Loading regions.shp");
        QString env = fc->envelope().toString();
        DOTEST(env == "33.0065 3.40088 47.9605 14.9637","FeatureCoverage: testing envelope (bbox)");

        DOTEST(fc.prepare(makeInputPath("rainfall.shp")),"loading point map");
        Ilwis::FeatureIterator iter1(fc);

        Ilwis::SPFeatureI f1 = *(iter1 + 1);
        QVariant output = f1->cell("RAINFALL");
        DOTEST(output.toString() =="taquina","accesing attribute string data of pointmap");

        Ilwis::SPFeatureI f2 = *(iter1 + 4);
        output = f2("JANUARY");
        DOCOMPARE(output.toInt(), 85 ,"accesing attribute numeric data of pointmap");

        DOTEST(fc.prepare(makeInputPath("drainage.shp")),"loading segment map");
        Ilwis::FeatureIterator iter2(fc);

        Ilwis::SPFeatureI f3 = *(iter2 + 104);
        output = f3->cell("DRAINAGE");
        DOTEST(output.toString() == "lake","accesing attribute string data of line coverage");

        Ilwis::SPFeatureI f4 = *(iter2 + 21);
        output = f4("C1");
        DOCOMPARE(output.toInt(), 1 ,"accesing attribute numeric data ofline coverage");

        DOTEST(fc.prepare(makeInputPath("geology.shp")),"loading polygon map");
        Ilwis::FeatureIterator iter3(fc);

        Ilwis::SPFeatureI f5 = *(iter3 + 40);
        output = f5->cell("GEOLOGY");
        DOTEST(output.toString() == "Shales","accesing attribute string data of polygon coverage");


    }catch (const Ilwis::ErrorObject& err) {
        QString error = "Test threw exception : " + err.message();
        QFAIL(error.toLatin1());
    }
}

void GdalDataAccess::accessingRasterData() {
    try {
        qDebug() << "Gridcoverage: access value through GDAL";

       // Ilwis::IRasterCoverage raster2(makeInputPath("g250_06.tif"));
       // DOCOMPARE(raster2->pix2value(Ilwis::Pixel(10549,9483)), 25.0,"accessing numerical value raster map");

        Ilwis::IRasterCoverage raster(makeInputPath("f41078a1.tif"));
        DOCOMPARE(raster->pix2value(Ilwis::Pixel(3278,2669)), 4.0,"accessing numerical value raster map");

        raster.prepare(makeInputPath("GCL_INT.tif"));
        DOCOMPARE(raster->pix2value(Ilwis::Pixel(239,297,23)), 48.0, "accessing numerical value in stack of raster (layer 24)");



    }catch (const Ilwis::ErrorObject& err) {
        QString error = "Test threw exception : " + err.message();
        QFAIL(error.toLatin1());
    }


}

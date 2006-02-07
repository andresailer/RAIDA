// #include <RAIDA/utilROOT.h>
#include <RAIDA/IProfile2DROOT.h>
#include <RAIDA/Naming.h>
#include <iostream>
#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TDirectory.h>
#include <string>

using namespace AIDA ;
using namespace std;

IProfile2DROOT::IProfile2DROOT(const std::string & name,
			       const std::string & title,
			       int nBinsX,
			       double lowerEdgeX,
			       double upperEdgeX,
			       int nBinsY,
			       double lowerEdgeY,
			       double upperEdgeY,
			       const std::string & options)
{
  _profile = new TProfile2D(name.c_str(),
			    title.c_str(),
			    (Int_t)nBinsX,
			    (Axis_t)lowerEdgeX,(Axis_t)upperEdgeX,
			    (Int_t)nBinsY,
			    (Axis_t)lowerEdgeY,(Axis_t)upperEdgeY);
  _histogram = new TH2D(Naming::binContents(name).c_str(),
                        Naming::titleBinContents(title).c_str(),
			(Int_t)nBinsX,
			(Axis_t)lowerEdgeX,(Axis_t)upperEdgeX,
			(Int_t)nBinsY,
			(Axis_t)lowerEdgeY,(Axis_t)upperEdgeY);
  _histogramAIDA = new TH2D(Naming::binEntry(name).c_str(),
                            Naming::titleBinEntry(title).c_str(),
                            (Int_t)nBinsX,
                            (Axis_t)lowerEdgeX,(Axis_t)upperEdgeX,
                            (Int_t)nBinsY,
                            (Axis_t)lowerEdgeY,(Axis_t)upperEdgeY);
  _histogramAIDABinMeanX = new TH2D(Naming::binMeanX(name).c_str(),
                                    Naming::titleBinMeanX(title).c_str(),
				    (Int_t)nBinsX,
				    (Axis_t)lowerEdgeX,(Axis_t)upperEdgeX,
				    (Int_t)nBinsY,
				    (Axis_t)lowerEdgeY,(Axis_t)upperEdgeY);
  _histogramAIDABinMeanY = new TH2D(Naming::binMeanY(name).c_str(),
                                    Naming::titleBinMeanY(title).c_str(),
				    (Int_t)nBinsX,
				    (Axis_t)lowerEdgeX,(Axis_t)upperEdgeX,
				    (Int_t)nBinsY,
				    (Axis_t)lowerEdgeY,(Axis_t)upperEdgeY);
}

bool IProfile2DROOT::fill(double x, double y, double z, double weight) 
{
  if (weight<0) {  return false; }

  int    iBin = (int)_histogram->FindBin( (Axis_t)x,(Axis_t)y );
  double iBinHeight = (double)_histogram->GetBinContent(iBin);
  double newBinMeanX, oldBinMeanX, newBinMeanY, oldBinMeanY;

  oldBinMeanX = (double)_histogramAIDABinMeanX->GetBinContent(iBin);
  newBinMeanX = (oldBinMeanX * iBinHeight + x*weight)/(weight+iBinHeight);
  oldBinMeanY = (double)_histogramAIDABinMeanY->GetBinContent(iBin);
  newBinMeanY = (oldBinMeanY * iBinHeight + y*weight)/(weight+iBinHeight);

  _histogramAIDABinMeanX->SetBinContent( (Int_t)iBin, (Stat_t)newBinMeanX );
  _histogramAIDABinMeanY->SetBinContent( (Int_t)iBin, (Stat_t)newBinMeanY );
  _profile->Fill( (Axis_t)x,(Axis_t)y,(Stat_t)weight );
  _histogram->Fill( (Axis_t)x,(Axis_t)y,(Stat_t)weight );
  _histogramAIDA->Fill( (Axis_t)x,(Axis_t)y,(Stat_t)1. );
  return true;
}

double IProfile2DROOT::binMeanX(int indexX, int indexY) const 
{
  return (double)_histogramAIDABinMeanX->GetBinContent( (Int_t)indexX,
                                                        (Int_t)indexY );
}

double IProfile2DROOT::binMeanY(int indexX, int indexY) const 
{
  return (double)_histogramAIDABinMeanY->GetBinContent( (Int_t)indexX,
                                                        (Int_t)indexY );
}

int IProfile2DROOT::binEntries(int indexX, int indexY) const 
{
  double binCount;
  binCount = (double)_histogramAIDA->GetBinContent( (Int_t)indexX,(Int_t)indexY);
  return (int)binCount;
}

int IProfile2DROOT::binEntriesX(int indexX) const 
{
  double sumX = 0;
  if (indexX < 0 || indexX > ((int)_histogramAIDA->GetNbinsX()+1))
    {
      return -99999;
    }
  for ( int i=0 ; i<=((int)_histogramAIDA->GetNbinsY()+1) ; i++)
    {
      sumX += (double)_histogramAIDA->GetBinContent( (Int_t)indexX,(Int_t)i );
    }
  return (int)sumX;
}

int IProfile2DROOT::binEntriesY(int indexY) const 
{
  double sumY = 0;
  if (indexY < 0 || indexY > ((int)_histogramAIDA->GetNbinsY()+1))
    {
      return -99999;
    }
  for ( int i=0 ; i<=((int)_histogramAIDA->GetNbinsX()+1) ; i++)
    {
      sumY += (double)_histogramAIDA->GetBinContent( (Int_t)i,(Int_t)indexY );
    }
  return (int)sumY;
}

double IProfile2DROOT::binHeight(int indexX, int indexY) const 
{
  if ( (indexX < 0 || indexX > ((int)_histogram->GetNbinsX()+1)) ||
       (indexY < 0 || indexY > ((int)_histogram->GetNbinsY()+1)) )
    {
      return -99999;
    }
  return (double)_profile->GetBinEntries(_profile->GetBin( (Int_t)indexX,(Int_t)indexY ));
}

double IProfile2DROOT::binHeightX(int indexX) const 
{
  double sumX = 0;
  if (indexX < 0 || indexX > ((int)_histogram->GetNbinsX()+1))
    {
      return -99999;
    }
  for ( int i=0 ; i<=((int)_histogram->GetNbinsY()+1) ; i++)
    {
      sumX += (double)_histogram->GetBinContent( (Int_t)indexX,(Int_t)i );
    }
  return sumX;
}

double IProfile2DROOT::binHeightY(int indexY) const 
{
  double sumY = 0;
  if (indexY < 0 || indexY < ((int)_histogram->GetNbinsY()+1))
    {
      return -99999;
    }
  for ( int i=0 ; i<=((int)_histogram->GetNbinsX()+1) ; i++)
    {
      sumY += (double)_histogram->GetBinContent( (Int_t)i,(Int_t)indexY );
    }
  return sumY;
}

double IProfile2DROOT::binError(int indexX, int indexY) const 
{
  return (double)_histogram->GetBinError( (Int_t)indexX,(Int_t)indexY );
}

double IProfile2DROOT::binRms(int indexX, int indexY) const 
{
  return (double)_profile->GetBinError( (Int_t)indexX,(Int_t)indexY );
}

double IProfile2DROOT::meanX() const 
{
  return (double)_profile->GetMean( (Int_t)1 );
}

double IProfile2DROOT::meanY() const 
{
  return (double)_profile->GetMean( (Int_t)2 );
}

double IProfile2DROOT::rmsX() const 
{
  return (double)_profile->GetRMS( (Int_t)1 );
}

double IProfile2DROOT::rmsY() const 
{
  return (double)_profile->GetRMS( (Int_t)2 );
}

int IProfile2DROOT::coordToIndexX(double coordX) const 
{
  TH1D *xProj;
  int xBin;

  xProj = _histogram->ProjectionX("_temphisto");
  xBin = (int)xProj->FindBin( (Axis_t)coordX );

  delete xProj;
  return xBin;
}

int IProfile2DROOT::coordToIndexY(double coordY) const 
{
  TH1D *yProj;
  int yBin;

  yProj = _histogram->ProjectionY("_temphisto");
  yBin = (int)yProj->FindBin( (Axis_t)coordY );

  delete yProj;
  return yBin;
}

int IProfile2DROOT::allEntries() const 
{
  return (int)_histogramAIDA->GetEntries();
}

int IProfile2DROOT::extraEntries() const 
{
  double noExtra = 0.;

  /*
   sum of extra-bins:
   i   = bins of the Histogram
   x/X = extra bins of the histogram
   The first loop will add alog the x, the second alog the y direction. 
   to not count the bins at the corners two times the loop runs once only 
   from 1 to n!

       |  0  |  1  |  2  | ... |  n  | n+1
   ---------------------------------------- (x)
   0   |  X  |  X  |  X  |  X  |  X  |  X
   1   |  x  |  i  |  i  |  i  |  i  |  x
   2   |  x  |  i  |  i  |  i  |  i  |  x
   ... | ... 
   n   |  x  |  i  |  i  |  i  |  i  |  x
   n+1 |  X  |  X  |  X  |  X  |  X  |  X
      (y)
   */

  for ( int i=0 ; i<=((int)_histogramAIDA->GetNbinsX()+1) ; i++ )
    {
      noExtra += (double)_histogramAIDA->GetBinContent( (Int_t)i,(Int_t)0 ); 
      noExtra += (double)_histogramAIDA->GetBinContent
          ( (Int_t)i,((Int_t)_histogramAIDA->GetNbinsY() + 1) ); 
    }

  /*
   sum of extra-bins:
       |  0  |  1  |  2  | ... |  n  | n+1
   ---------------------------------------- (x)
   0   |  x  |  x  |  x  |  x  |  x  |  x
   1   |  X  |  i  |  i  |  i  |  i  |  X
   2   |  X  |  i  |  i  |  i  |  i  |  X
   ... | ... 
   n   |  X  |  i  |  i  |  i  |  i  |  X
   n+1 |  x  |  x  |  x  |  x  |  x  |  x
      (y)
   */

  for ( int i=1 ; i<=(int)_histogramAIDA->GetNbinsY() ; i++ )
    {
      noExtra += (double)_histogramAIDA->GetBinContent( (Int_t)0,(Int_t)i ); 
      noExtra += (double)_histogramAIDA->GetBinContent
          ( ((Int_t)_histogramAIDA->GetNbinsX() + 1),(Int_t)i ); 
    }

  return (int)noExtra;
}

double IProfile2DROOT::sumBinHeights() const 
{
  double integral = 0.;

  for ( int i=1 ; i<=(int)_histogram->GetNbinsX() ; i++ )
    {
      for ( int j=1 ; j<=(int)_histogram->GetNbinsY() ; j++ )
        {
          integral += (double)_histogram->GetBinContent( (Int_t)i,(Int_t)j );
        }
    }
  return integral;
}

double IProfile2DROOT::sumAllBinHeights() const 
{
  double integral = 0.;

  for ( int i=0 ; i<=((int)_histogram->GetNbinsX()+1) ; i++ )
    {
      for ( int j=0 ; j<=((int)_histogram->GetNbinsY()+1) ; j++ )
        {
          integral += (double)_histogram->GetBinContent(i,j);
        }
    }
  return integral;
}

double IProfile2DROOT::sumExtraBinHeights() const 
{
  double intExtra = 0.;

  /*
   sum of extra-bins:
   i   = bins of the Histogram
   x/X = extra bins of the histogram
   The first loop will add alog the x, the second alog the y direction. 
   to not count the bins at the corners two times the loop runs once only 
   from 1 to n!

       |  0  |  1  |  2  | ... |  n  | n+1
   ---------------------------------------- (x)
   0   |  X  |  X  |  X  |  X  |  X  |  X
   1   |  x  |  i  |  i  |  i  |  i  |  x
   2   |  x  |  i  |  i  |  i  |  i  |  x
   ... | ... 
   n   |  x  |  i  |  i  |  i  |  i  |  x
   n+1 |  X  |  X  |  X  |  X  |  X  |  X
      (y)
   */

  for ( int i=0 ; i<=((int)_histogram->GetNbinsX()+1) ; i++ )
    {
      intExtra += (double)_histogram->GetBinContent( (Int_t)i,(Int_t)0 ); 
      intExtra += (double)_histogram->GetBinContent
          ( (Int_t)i,((Int_t)_histogram->GetNbinsY() + 1) ); 
    }

  /*
   sum of extra-bins:
       |  0  |  1  |  2  | ... |  n  | n+1
   ---------------------------------------- (x)
   0   |  x  |  x  |  x  |  x  |  x  |  x
   1   |  X  |  i  |  i  |  i  |  i  |  X
   2   |  X  |  i  |  i  |  i  |  i  |  X
   ... | ... 
   n   |  X  |  i  |  i  |  i  |  i  |  X
   n+1 |  x  |  x  |  x  |  x  |  x  |  x
      (y)
   */

  for ( int i=1 ; i<=(int)_histogram->GetNbinsY() ; i++ )
    {
      intExtra += (double)_histogram->GetBinContent( (Int_t)0,(Int_t)i ); 
      intExtra += (double)_histogram->GetBinContent
          ( ((Int_t)_histogramAIDA->GetNbinsX() + 1),(Int_t)i ); 
    }

  return intExtra;
}

double IProfile2DROOT::minBinHeight() const 
{
  double minHeight;
  minHeight = (double)_histogram->GetBinContent( (Int_t)1,(Int_t)1 );

  for (int i = 1; i<=(int)_histogram->GetNbinsX();i++)
    {
      for ( int j=1 ; j<=(int)_histogram->GetNbinsY() ; j++ )
        {
          if ( (double)_histogram->GetBinContent( (Int_t)i,(Int_t)j ) < minHeight)
            {
              minHeight = (double)_histogram->GetBinContent( (Int_t)i,(Int_t)j );
            }
        }
    }
  return minHeight;
}

double IProfile2DROOT::maxBinHeight() const 
{
  double maxHeight;
  maxHeight = (double)_histogram->GetBinContent( (Int_t)1,(Int_t)1 );

  for ( int i=1 ; i<=(int)_histogram->GetNbinsX() ; i++)
    {
      for ( int j=1 ; j<=(int)_histogram->GetNbinsY() ; j++ )
        {
          if ( (double)_histogram->GetBinContent( (Int_t)i,(Int_t)j ) > maxHeight)
            {
              maxHeight = (double)_histogram->GetBinContent( (Int_t)i,(Int_t)j );
            }
        }
    }
  return maxHeight;
}

std::string IProfile2DROOT::title() const 
{
  string a(_profile->GetTitle());
  return a;
}

bool IProfile2DROOT::setTitle(const std::string & title) 
{
  _profile->SetTitle( title.c_str() );
  _histogram->SetTitle( Naming::titleBinContents(title).c_str() );
  _histogramAIDA->SetTitle( Naming::titleBinEntry(title).c_str() );
  _histogramAIDABinMeanX->SetTitle( Naming::titleBinMeanX(title).c_str() );
  _histogramAIDABinMeanY->SetTitle( Naming::titleBinMeanY(title).c_str() );
  return true;
}

int IProfile2DROOT::dimension() const 
{
  return (int)_profile->GetDimension();
}

bool IProfile2DROOT::reset() 
{
  _profile->Reset("");
  _histogram->Reset("");
  _histogramAIDA->Reset("");
  _histogramAIDABinMeanX->Reset("");
  _histogramAIDABinMeanY->Reset("");
  return true;
}

int IProfile2DROOT::entries() const 
{
  double integral = 0.;

  for ( int i=1 ; i<=(int)_histogramAIDA->GetNbinsX() ; i++ )
    {
      for ( int j=1 ; j<=(int)_histogramAIDA->GetNbinsY() ; j++ )
        {
          integral += (double)_histogramAIDA->GetBinContent( (Int_t)i,(Int_t)j );
        }
    }
  return (int)integral;
}
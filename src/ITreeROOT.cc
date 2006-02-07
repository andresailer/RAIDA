#include <RAIDA/ITreeROOT.h>

#include <iostream>
#include <TFile.h>
#include <string>

using namespace AIDA ;
using namespace std;

ITreeROOT::ITreeROOT(const std::string & storeName,
		     const std::string & storeType,
		     bool readOnly,
		     bool createNew,
		     const std::string &options)
{
  string RWMode;
  if (createNew && readOnly)
    {
      RWMode = "READ";
    }
  else if (!createNew && readOnly)
    {
      RWMode = "READ";
    }
  else if (createNew && !readOnly)
    {
      RWMode = "RECREATE";
    }
  else if (!createNew && !readOnly)
    {
      RWMode = "UPDATE";
    }

  // save storeName because ROOT can not return it
  _storeName = storeName;

  _ROOTFile = new TFile(storeName.c_str(),RWMode.c_str(),"ROOT_AIDA",0);
}

ITreeROOT::~ITreeROOT()
{
  cout << "Destruktor von tree" << endl;
  delete _ROOTFile;
}

bool ITreeROOT::commit()
{
  if (_ROOTFile) 
    {
      //      _ROOTFile->mkdir("mydir","mydir");
      _ROOTFile->Write();
      //_ROOTFile->ls("-d");
  gDirectory->ls("-d");
      return true;
    }
  else 
    {
      return false; 
    }
}

bool ITreeROOT::close()
{
  if (_ROOTFile) 
    {
      gDirectory->pwd();
      _ROOTFile->Close();
      gDirectory->pwd();
      return true;
    }
  else 
    {
      return false; 
    }
}

std::string ITreeROOT::storeName() const
{
  return _storeName;
}

bool ITreeROOT::cd(const std::string & path)
{
  string localPath("");
  if (path != "" && path[0] == '/')
    {
      localPath = storeName();
      localPath += ":";
      localPath += path;
    }
  else if (path != "" && path[0] != '/')
    {
      localPath = path;
    }

  return (bool)gDirectory->cd(localPath.c_str());
  //  return (bool)_ROOTFile->cd(localPath.c_str());
}

std::string ITreeROOT::pwd() const
{
  int length = _storeName.length() + 1; // because of the ":"
  string thePath(gDirectory->GetPath());
  thePath.replace(0,length,"",0);
  return thePath;
}

bool ITreeROOT::mkdir(const std::string & path)
{
  string leftPath;
  string localPath = path;
  string subDirectory;

  // terminate if path is empty 
  if (localPath == "") return false; 

  // strip trailing "/" and leading "./" 
  while (localPath.rfind("/") == localPath.length()-1) 
    {
      localPath.erase(localPath.rfind("/"));
    }
  if (localPath.find("./") == 0) localPath.erase(0,2);

  if (localPath.rfind(("/")) == string::npos) 
    { // simple sub-directory
      subDirectory = localPath;
    }
  else  
    { // path consists of two parts: Sub-directory + leading path
      subDirectory = localPath.substr(localPath.rfind(("/"))+1);
      leftPath = localPath; 
      leftPath.erase(leftPath.rfind("/"));
    }

  // check if all leading sub-directories exist 
  string currentDir = pwd();
  if (leftPath != "")
    {
      if (!cd(leftPath)) return false;
    }

  // sub-directory to be created already exists ?
  if (cd(subDirectory))
    {
      cd(currentDir);
      return false;
    }

  // Subdirectory exists but is an other object
  string temp = subDirectory; temp += ";*";
  if (_ROOTFile->Get(temp.c_str()))
    {
      cd(currentDir);
      return false;
    }

  // create the sub-directory:
  gDirectory->mkdir(subDirectory.c_str(),subDirectory.c_str());

  cd(currentDir);
  return true;
}
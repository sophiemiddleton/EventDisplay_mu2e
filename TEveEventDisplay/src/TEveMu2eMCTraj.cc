#include "TEveEventDisplay/src/TEveMu2e_base_classes/TEveMu2eMCTraj.h"
#include "TEveEventDisplay/src/dict_classes/GeomUtils.h"
using namespace mu2e;
namespace mu2e{

  void TEveMu2eMCTraj::DrawHit3D(const std::string &pstr, Int_t n, CLHEP::Hep3Vector pointInMu2e, TEveElementList *HitList)
  {
    std::string hstr=" hit %d";
    std::string dstr=" hit# %d\nLayer: %d";
    std::string strlst=pstr+hstr;
    std::string strlab=pstr+dstr;
    hep3vectorTocm(pointInMu2e);
    this->SetTitle(Form(strlab.c_str(),n,hstr));
    this->SetNextPoint(pointInMu2e.x(), pointInMu2e.y(), pointInMu2e.z()); 
    this->SetMarkerColor(kBlue);
    this->SetMarkerSize(2);
    this->SetPickable(kTRUE);
    HitList->AddElement(this);
  }

 void TEveMu2eMCTraj::DrawLine3D(const std::string &pstr,  CLHEP::Hep3Vector Start, CLHEP::Hep3Vector End, TEveElementList *HitList)
  {
    std::string hstr=" hit %d";
    std::string dstr=" hit# %d\nLayer: %d";
    std::string strlst=pstr+hstr;
    std::string strlab=pstr+dstr;
    hep3vectorTocm(Start);
    std::cout<<" Start "<<Start.x()<<" "<<Start.y()<<" "<<Start.z()<<std::endl;
    hep3vectorTocm(End);
    std::cout<<" End "<<End.x()<<" "<<End.y()<<" "<<End.z()<<std::endl;
    this->SetTitle(Form(strlab.c_str(),hstr));
    TEveLine *line = new TEveLine();
    line->SetPoint(0, Start.x()-390.4, Start.y()+231.2, Start.z()+128.8+300); 
    line->SetNextPoint(End.x()-390.4, End.y()+231.2, End.z()+128.8+300); 
    line->SetLineColor(kYellow);
    this->SetMarkerColor(kBlue);
    this->SetMarkerSize(2);
    this->SetPickable(kTRUE);
    HitList->AddElement(line);
    HitList->AddElement(this);
  }
}

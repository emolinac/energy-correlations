#include "../include/analysis-constants.h"
#include "../include/analysis-cuts.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/utils-visual.h"

void macro_print_norme2c_data_jetpt()
{
    // Open ROOT file with ntuple
    TFile* f = new TFile((output_folder+namef_ntuple_e2c).c_str());

    // Get the ntuple
    TNtuple* ntuple = (TNtuple*) f->Get((name_ntuple_data).c_str());
    
    // Determine binning
    double binning[Nbin_X_L+1];
    determine_log10binning(Nbin_X_L, X_L_min, X_L_max, binning);

    TH1F* h_1 = new TH1F("h_1","",Nbin_X_L, binning);
    TH1F* h_2 = new TH1F("h_2","",Nbin_X_L, binning);
    TH1F* h_3 = new TH1F("h_3","",Nbin_X_L, binning);
    h_1->Sumw2();
    h_2->Sumw2();
    h_3->Sumw2();

    // Create Canvas and draw in it
    TCanvas* c = new TCanvas("","",800,600);
    c->Draw();
    ntuple->Draw("X_L>>h_1",e2c_jetpt_cut[0],"goff");
    ntuple->Draw("X_L>>h_2",e2c_jetpt_cut[1],"goff");
    ntuple->Draw("X_L>>h_3",e2c_jetpt_cut[2],"goff");

    h_1->Scale(1./h_1->Integral());
    h_2->Scale(1./h_2->Integral());
    h_3->Scale(1./h_3->Integral());

    set_histogram_style(h_1 , kViolet+2 , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_2 , kCyan     , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_3 , kGreen+2  , std_line_width, std_marker_style, std_marker_size);

    THStack* s = new THStack();
    s->Add(h_1);
    s->Add(h_2);
    s->Add(h_3);
    s->Draw("NOSTACK");
    s->SetTitle(";X_{L};Norm. E2C");

    s->SetMaximum(1);

    gPad->SetLogx(1);
    gPad->SetLogy(1);

    TLegend* l = new TLegend();
    l->AddEntry(h_1,"20<Jet p_{T}<30 GeV","lpf");
    l->AddEntry(h_2,"30<Jet p_{T}<50 GeV","lpf");
    l->AddEntry(h_3,"50<Jet p_{T}<100 GeV","lpf");
    l->Draw("SAME");

    c->Print("../plots/normE2C_data_jetpt.pdf");
}
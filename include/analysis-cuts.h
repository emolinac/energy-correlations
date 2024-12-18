#ifndef ANALYSIS_CUTS_H
#define ANALYSIS_CUTS_H

#include "TCut.h"
#include "TString.h"
#include "analysis-constants.h"

// _______________________________ Z Tagged Jet Cuts _______________________________ //

// Trigger cuts
const bool trigger_lines = true;

// Jet cuts
const double jet_eta_min = 2.5;
const double jet_eta_max = 4.0;
const double jet_pt_min  = 15;

// Topological cuts
const double deltaphi_z_jet_min  = 7*TMath::Pi()/8.;
const double deltar_muon_jet_min = 0.5;

// Z boson cuts
const double muon_pt_min  = 20.;
const double muon_eta_min = 2;
const double muon_eta_max = 4.5;
const double muonmuon_mass_min = 60;
const double muonmuon_mass_max = 120;
const double muon_trackprob_min = 0.001;

// Track cuts
const double track_chi2ndf_max     = 3;
const double track_p_min           = 4;
const double track_p_max           = 1000;
const double track_pt_min          = 0.25;
const double track_probnnghost_max = 0.5;

// _______________________________ Nominal Analysis Cuts _______________________________ //

TCut e2c_cut  = Form("weight*(jet_pt>%f&&jet_pt<%f)",jet_pt_min_nom,jet_pt_max);
TCut pair_cut = Form("jet_pt>%f&&jet_pt<%f",jet_pt_min_nom,jet_pt_max);

// Cuts as function of jet pt
TCut e2c_jetpt_cut[] = 
{Form("weight*(jet_pt>%f&&jet_pt<%f)",jet_pt_binning[0],jet_pt_binning[1]),
 Form("weight*(jet_pt>%f&&jet_pt<%f)",jet_pt_binning[1],jet_pt_binning[2]),
 Form("weight*(jet_pt>%f&&jet_pt<%f)",jet_pt_binning[2],jet_pt_binning[3])};

TCut pair_jetpt_cut[] = 
{Form("jet_pt>%f&&jet_pt<%f",jet_pt_binning[0],jet_pt_binning[1]),
 Form("jet_pt>%f&&jet_pt<%f",jet_pt_binning[1],jet_pt_binning[2]),
 Form("jet_pt>%f&&jet_pt<%f",jet_pt_binning[2],jet_pt_binning[3])};

// _______________________________ Purity Analysis Cuts _______________________________ //
TCut pair_signal_cut   = Form("TMath::Abs(R_L_truth-R_L)<%f&&jet_pt>%f&&jet_pt<%f",R_L_res,jet_pt_min_nom,jet_pt_max);
TCut pair_pairbg_cut   = Form("(h1truth_y==-999&&h2truth_y==-999)&&jet_pt>%f&&jet_pt<%f",jet_pt_min_nom,jet_pt_max);
TCut pair_singlebg_cut = Form("((h1truth_y==-999&&h2truth_y!=-999)||(h1truth_y!=-999&&h2truth_y==-999))&&jet_pt>%f&&jet_pt<%f",jet_pt_min_nom,jet_pt_max);
TCut single_signal_cut = Form("h2truth_phi!=-999&&jet_pt>%f&&jet_pt<%f",jet_pt_min_nom,jet_pt_max); // This was designed for single particle tuples

TCut e2c_signal_cut   = Form("weight*(TMath::Abs(R_L_truth-R_L)<%f&&jet_pt>%f&&jet_pt<%f)",R_L_res,jet_pt_min_nom,jet_pt_max);
TCut e2c_pairbg_cut   = Form("weight*((h1truth_y==-999&&h2truth_y==-999)&&jet_pt>%f&&jet_pt<%f)",jet_pt_min_nom,jet_pt_max);
TCut e2c_singlebg_cut = Form("weight*(((h1truth_y==-999&&h2truth_y!=-999)||(h1truth_y!=-999&&h2truth_y==-999))&&jet_pt>%f&&jet_pt<%f)",jet_pt_min_nom,jet_pt_max);

TCut pair_jetpt_signal_cut[] = 
{
Form("TMath::Abs(R_L_truth-R_L)<%f&&jet_pt>%f&&jet_pt<%f",R_L_res,jet_pt_binning[0],jet_pt_binning[1]),
Form("TMath::Abs(R_L_truth-R_L)<%f&&jet_pt>%f&&jet_pt<%f",R_L_res,jet_pt_binning[1],jet_pt_binning[2]),
Form("TMath::Abs(R_L_truth-R_L)<%f&&jet_pt>%f&&jet_pt<%f",R_L_res,jet_pt_binning[2],jet_pt_binning[3])
};

TCut pair_jetpt_pairbg_cut[] = 
{
Form("(h1truth_y==-999&&h2truth_y==-999)&&jet_pt>%f&&jet_pt<%f",jet_pt_binning[0],jet_pt_binning[1]),
Form("(h1truth_y==-999&&h2truth_y==-999)&&jet_pt>%f&&jet_pt<%f",jet_pt_binning[1],jet_pt_binning[2]),
Form("(h1truth_y==-999&&h2truth_y==-999)&&jet_pt>%f&&jet_pt<%f",jet_pt_binning[2],jet_pt_binning[3])
};

TCut pair_jetpt_singlebg_cut[] = 
{
Form("((h1truth_y==-999&&h2truth_y!=-999)||(h1truth_y!=-999&&h2truth_y==-999))&&jet_pt>%f&&jet_pt<%f",jet_pt_binning[0],jet_pt_binning[1]),
Form("((h1truth_y==-999&&h2truth_y!=-999)||(h1truth_y!=-999&&h2truth_y==-999))&&jet_pt>%f&&jet_pt<%f",jet_pt_binning[1],jet_pt_binning[2]),
Form("((h1truth_y==-999&&h2truth_y!=-999)||(h1truth_y!=-999&&h2truth_y==-999))&&jet_pt>%f&&jet_pt<%f",jet_pt_binning[2],jet_pt_binning[3])
};

#endif
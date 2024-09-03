#ifndef NAMES_H
#define NAMES_H

// Names of the files
std::string namef_ntuple_e2c    = "ntuple_e2c.root";

// Name of the ntuples
std::string name_ntuple_unfold = "ntuple_unfold";
std::string name_ntuple_data   = "ntuple_data";
std::string name_ntuple_mc     = "ntuple_mc";
std::string name_ntuple_mcreco = "ntuple_mcreco";

// TNTuples variables
const int Nvars_unfold = 16; 
const int Nvars_mc     = 21; 
const int Nvars_mcreco = 42; 
const int Nvars_data   = 42; 

//const char* ntuple_unfold_vars = "weight_true:weight_reco:X_L_true:X_L_reco:
//                                  h1_eta_true:h2_eta_true:h1_phi_true:h2_phi_true:h1_p_true:h2_p_true:
//                                  h1_eta_reco:h2_eta_reco:h1_phi_reco:h2_phi_reco:h1_p_reco:h2_p_reco:h1_pt_reco:h2_pt_reco:
//                                  h1_probnnghost_reco:h2_probnnghost_reco:h1_chi2_reco:h2_chi2_reco:h1_ndf_reco:h2_ndf_reco:
//                                  ";

const char* ntuple_mc_vars     = "weight:X_L:h1_id:h2_id:h1_eta:h2_eta:h1_phi:h2_phi:h1_motherid:h2_motherid:h1_topmotherid:h2_topmotherid:h1_p:h2_p:h1_pt:h2_pt:h1_pz:h2_pz:jet_pt:jet_eta:jet_phi";
const char* ntuple_mcreco_vars = "weight:X_L:h1_id:h2_id:h1_eta:h2_eta:h1_phi:h2_phi:h1_chi2:h2_chi2:h1_ndf:h2_ndf:h1_probnnghost:h2_probnnghost:h1_p:h2_p:h1_pt:h2_pt:h1_pz:h2_pz:jet_pt:jet_eta:jet_phi:z0_phi:mum_phi:mum_pt:mum_eta:mum_px:mum_py:mum_pz:mum_pe:mum_m:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_px:mup_py:mup_pz:mup_pe:mup_m:mup_probchi2";
const char* ntuple_data_vars   = "weight:X_L:h1_id:h2_id:h1_eta:h2_eta:h1_phi:h2_phi:h1_chi2:h2_chi2:h1_ndf:h2_ndf:h1_probnnghost:h2_probnnghost:h1_p:h2_p:h1_pt:h2_pt:h1_pz:h2_pz:jet_pt:jet_eta:jet_phi:z0_phi:mum_phi:mum_pt:mum_eta:mum_px:mum_py:mum_pz:mum_pe:mum_m:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_px:mup_py:mup_pz:mup_pe:mup_m:mup_probchi2";
#endif
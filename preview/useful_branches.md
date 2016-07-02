#List of potentially useful branches for MVA testing/training

## Regarding initial state
- **neu (int): Neutrino PDG code.**
Obs: Hit nucleus is always C12

- hitnuc (int): Hit nucleon PDG code (not set for coherent, inverse muon decay and ve- elastic
events).
- hitqrk (int): Hit quark PDG code (set for deep-inelastic scattering events only).
- sea (bool ): Hit quark is from sea (set for deep-inelastic scattering events only).



## Regarding Interaction/Scattering channel. Useful for testing and adressing the main source of dilepton/dimuon events
- **nc (bool ): Is it a NC event?**
- **cc (bool ): Is it a CC event?**
- **qel (bool ): Is it a quasi-elastic scattering event?**
- **res (bool ): Is it a resonanec neutrino-production event?**
- **dis (bool ): Is it a deep-inelastic scattering event?**
- **coh (bool ): Is it a coherent meson production event?**
- **dfr (bool ): Is it a diffractive meson production event?**
 Obs: Neutrino - Electron elastic and invese muon decay events are discarded as they cannot produce dileptons

## Regarding produced states
- **nmuons (int ): Number of muons in final state. This comes from MC truth and is our primary signal/background discriminant**
- **charm (bool ): Produces charm?**
- **resid (bool ): Produced baryon resonance id (set for resonance events only).**


## Regarding Event kinematics (very useful, as they can generally be reconstructed from data)
- **Ev (double): Incoming neutrino energy (in GeV)**
- **x (double): Bjorken x (as computed from the event record).**
- **y (double): Inelasticity y (as computed from the event record).**
- **t (double): Energy transfer to nucleus (nucleon) at coherent (diffractive) production events (as computed from the event record).**
- **Q2 (double): Momentum transfer Q 2 (as computed from the event record) (in GeV 2 ).**
- **W (double): Hadronic invariant mass W (as computed from the event record).**
- **Wlep: reconstructed dilepton pair invariant mass**
- **calresp0 (double): An approximate calorimetric response to the generated hadronic vertex actibity.**

## Others, only for testing purposes
Obs: We have always two leptons, so thath we don't know which is the final state primary lepton
- En (double): Initial state hit nucleon energy (in GeV).
- pxn (double): Initial state hit nucleon px (in GeV).
- pyn (double): Initial state hit nucleon py (in GeV).
- pzn (double): Initial state hit nucleon pz (in GeV).
- El (double): Final state primary lepton energy (in GeV).
- pxl (double): Final state primary lepton px (in GeV).
- pyl (double): Final state primary lepton py (in GeV).
- pzl (double): Final state primary lepton pz (in GeV).

- nfp (int): Number of final state p and p  ̄ (after intranuclear rescattering)
- nfn (int): Number of final state n and nbar
- nfpip (int): Number of final state ⇡ + .
- nfpim (int): Number of final state ⇡ .
- nfpi0 (int): Number of final state ⇡ 0 .
- nfkp (int): Number of final state K + .
- nfkm (int): Number of final state K .
- nfk0 (int): Number of final state K 0 and K  ̄ 0 .
- nfem (int): Number of final state , e and e + .

- nfother (int): Number of heavier final state hadrons (D+/-,D0,Ds+/-,Lamda,Sigma,Lamda_c,Sigma_c,...)

- nip (int): Number of ‘primary’ (‘primary’ : before intranuclear rescattering) p and p ̄ .
 nin (int): Number of ‘primary’ n and n- 
- nipip (int): Number of ‘primary’ \Pi + .
- nipim (int): Number of ‘primary’ \Pi .
- nipi0 (int): Number of ‘primary’ \Pi 0 .
- nikp (int): Number of ‘primary’ K + .
- nikm (int): Number of ‘primary’ K .
- nik0 (int): Number of ‘primary’ K 0 and K  ̄ 0 .
- niem (int): Number of ‘primary’ , e and e + (eg from nuclear de excitations or from pre-intranuked resonance decays) 
- niother (int): Number of other ‘primary’ hadron shower particles.


## Also only for testing purposes, as the only particles we can really reconstruct from data are muons, in general
- nf (int): Number of final state particles in hadronic system.
- pdgf (int[kNPmax] ): PDG code of k th final state particle in hadronic system.
- Ef (double[kNPmax] ): Energy of k th final state particle in hadronic system (in GeV).
- pxf (double[kNPmax] ): Px of k th final state particle in hadronic system (in GeV).
- pyf (double[kNPmax] ): Py of k th final state particle in hadronic system (in GeV).
- pzf (double[kNPmax] ): Pz of k th final state particle in hadronic system (in GeV).


## Other observations: 
- The primary hadronics system is completely unknow to the experiment... But we may, for testing proposes, check for eta mesons, which seem to give the greatest quantity of dileptons
- Vertex makes no sense in our parameterized MINERvA

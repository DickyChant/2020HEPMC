// main32.cc is a part of the PYTHIA event generator.
// Copyright (C) 2019 Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

// This is a sample program showing Alpgen- or Madgraph-style MLM matching
// for Madgraph LHEF or native Alpgen format event files.
//
// Please see the 'Jet Matching Style' manual page for a description of the
// parameters and user options.

// Includes and namespace
#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/CombineMatchingInput.h"
#include "TTree.h"
#include "TFile.h"
#include <string.h>
using namespace Pythia8;

//==========================================================================

int main() {
  TFile* outFile = new TFile("p8.root", "RECREATE");
  double ptz, ez;
  TTree *t = new TTree("t","t");
  t->Branch("ptz",&ptz);
  t->Branch("ez",&ez);

 // Generator and read in commands.
  Pythia pythia;
  pythia.readFile("main32.cmnd");

  // Extract settings to be used in the main program.
  int nEvent = pythia.mode("Main:numberOfEvents");
  int nAbort = pythia.mode("Main:timesAllowErrors");
  int nSkip  = pythia.mode("Main:spareMode1");

  // Create UserHooks pointer. Stop if it failed. Pass pointer to Pythia.
  CombineMatchingInput combined;
  combined.setHook(pythia);
  auto matching = combined.hook;
  if (!matching) return 1;
  pythia.setUserHooksPtr(matching);

  // Initialise Pythia.
  if (!pythia.init()) {
    cout << "Error: could not initialise Pythia" << endl;
    return 1;
  };

  // Optionally skip ahead in LHEF.
  pythia.LHAeventSkip( nSkip );

  // Begin event loop. Optionally quit it before end of file.
  int iAbort = 0;
  for (int iEvent = 0; ;  ++iEvent) {
    if (nEvent > 0 && iEvent >= nEvent) break;

    // Generate events. Quit if at end of file or many failures.
    if (!pythia.next()) {
      if (pythia.info.atEndOfFile()) {
        cout << "Info: end of input file reached" << endl;
        break;
      }
      if (++iAbort < nAbort) continue;
      cout << "Abort: too many errors in generation" << endl;
      break;
    }
    // Event analysis goes here.
    int iZ = 0;
    for (int i = 0; i < pythia.event.size(); ++i)
      if (pythia.event[i].id() == 23) { iZ = i; }
    ptz=pythia.event[iZ].pT();
    ez=pythia.event[iZ].e();
  // End of event loop. Statistics. Histogram. Done.
    t->Fill();
  // End of event loop.
  }

  // Final statistics and done.
  pythia.stat();
  t->Write();
  //delete matching;
  outFile->Close();

  return 0;
}

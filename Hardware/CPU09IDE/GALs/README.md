These are the GAL spec's for this board. All made available under GPL V3. Copyright (c) C. Schoenmakers 2019


2020-03-11: IDE_1.PDS has been slightly changed to make sure that /ADEN only happens during DACK. Some drives like that better.

2020-04-13: IDE_G1.PDS has been modified to minimize delay times
IDE_G2.PDS has been modified, DMARQ is now synchronized with QE clock, this eliminates some ugly glitches

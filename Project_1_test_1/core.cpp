/*

//------- Imports -------
#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 

using namespace::std;



//------- Main ---------
int main() {
    int sample_rate = 100; // samples per second, select value which provides good quality sound  
    double duration = 10; // how long [seconds] it will sound 
    double n_samples = duration * sample_rate; // if sound is "duration" seconds long and there are "sample_rate" samples per second 
    // - how many samples are there altogether? What type should this variable be? 

    //... dt = ...; // time between samples 
    //int* waveform = new int[n_samples]; // creates the array 

    // or you can use vector 
    std::vector<int> waveform;
    int frequency = 24000;// pitch of the sound 
    int volume = 30000;// 6000 is loud enough 

    for (int i_sample = 0; i_sample < n_samples; i_sample++) {
        cout << "test text";
        // if using vector 
        waveform.push_back(frequency);
        //cout an be used here to check values of "waveform" 
        cout << frequency;
    }
    // generates sound file from waveform array, writes n_samples numbers  
    // into sound wav file 
    // should know sample_rate for sound timing 
    // if using vector 
    MakeWavFromVector("tone1.wav", sample_rate, waveform); //file name can be changed but keep extension .wav 
    waveform.clear(); //if using vectors 
    return 0;
}

*/

//------- Imports -------
#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 

using namespace::std;

//------- Main ---------
int main() {
    int sample_rate = 10000; // samples per second, select value which provides good quality sound  
    double duration = 10; // how long [seconds] it will sound 
    double n_samples = duration * sample_rate; // if sound is "duration" seconds long and there are "sample_rate" samples per second 
    float dt = 1.0 / sample_rate;
    // - how many samples are there altogether? What type should this variable be? 

    //... dt = ...; // time between samples 
    //int* waveform = new int[n_samples]; // creates the array 

    // or you can use vector 
    std::vector<int> waveform;
    int frequency = 900;// pitch of the sound 
    int volume = 6000;// 6000 is loud enough 

    for (int i_sample = 0; i_sample < n_samples; i_sample++) {
        // if using vector 
        waveform.push_back(volume * sin(2 * 3.14159 * frequency * i_sample * dt));
        //cout an be used here to check values of "waveform" 
    }
    // generates sound file from waveform array, writes n_samples numbers  
    // into sound wav file 
    // should know sample_rate for sound timing 
    // if using vector 
    MakeWavFromVector("tone1.wav", sample_rate, waveform); //file name can be changed but keep extension .wav 
    waveform.clear(); //if using vectors 
    return 0;
}



//------- Imports -------
#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 

using namespace::std;

//------- Global ---------
//44100 is cd quality
int sample_rate = 300; // samples per second, select value which provides good quality sound  

int num_of_cycles = 10; //how many times it will play the 2 tones

int first_tone_duration = 1; //how long in seconds the first tone will be
int second_tone_duration = 2; //how long the in seconds the second tone will be
double total_duration = num_of_cycles * first_tone_duration * second_tone_duration; // how long [seconds] it will sound 

int single_cycle_samples = sample_rate * (first_tone_duration + second_tone_duration);

double n_samples = total_duration * sample_rate; // if sound is "duration" seconds long and there are "sample_rate" samples per second 

// - how many samples are there altogether? What type should this variable be? 
float dt = 1.0 / sample_rate; // time between samples 


//------- Main ---------
int main() {
    // or you can use vector 
    std::vector<int> waveform;
    float first_tone_frequincy = 1500;
    float second_tone_frequincy = 600;
    int volume = 30000;// 6000 is loud enough 

    int cycle_num = 0;

    for (int cycle_num = 0; cycle_num < num_of_cycles; cycle_num += 1) {
        for (int i_sample = 0; i_sample < single_cycle_samples; i_sample += 1) {
            if (i_sample < first_tone_duration * sample_rate) {
                waveform.push_back(static_cast<int>(volume * sin(2 * 3.14159 * first_tone_frequincy * i_sample * dt)));
            }
            else if (i_sample < second_tone_duration * sample_rate) {
                waveform.push_back(static_cast<int>(volume * sin(2 * 3.14159 * second_tone_frequincy * i_sample * dt)));
            }
        }
    }


    // generates sound file from waveform array, writes n_samples numbers  
    // into sound wav file 
    // should know sample_rate for sound timing 
    // if using vector 
    MakeWavFromVector("tone1.wav", sample_rate, waveform); //file name can be changed but keep extension .wav 
    waveform.clear(); //if using vectors 
    return 0;
}


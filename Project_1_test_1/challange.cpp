//------- Imports -------
#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 

using namespace::std;

//------- Global ---------

string fileName = "anotherbrickinthewall.txt";

int volume = 30000;// 6000 is loud enough 

int samplesPerNote = 300;
float noteDuration = 0.13;

int sampleRate = samplesPerNote / noteDuration; // samples per second, select value which provides good quality sound  
float dt = 1.0 / sampleRate; // time between samples 


std::vector<int> waveForm;

//------- Functions ---------

vector<float> readFile(string fileName) {
    ifstream openedFile;
    openedFile.open(fileName);
    vector<float> frequincys;
    string line;
    while (getline(openedFile,line)) {
        
        frequincys.push_back(stof(line));
    }
    return(frequincys);
}


//------- Main ---------
int main() {



    vector<float> rawWaveForm = readFile(fileName);


    for (int currentNote = 0; currentNote < rawWaveForm.size(); currentNote += 1) {
        for (int currentSample = 0; currentSample < samplesPerNote; currentSample += 1) {
            if (currentSample < 50) {
                waveForm.push_back(static_cast<int>(volume * (sin(2 * 3.14159 * rawWaveForm[currentNote] * currentSample * dt) + sin(2 * 3.14159 * (rawWaveForm[currentNote] / 2) * currentSample * dt) + sin(2 * 3.14159 * (rawWaveForm[currentNote] / 4) * currentSample * dt) + sin(2 * 3.14159 * (rawWaveForm[currentNote] / 8) * currentSample * dt))));

            }
        }
    }

    cout << waveForm.size();


    MakeWavFromVector("tone1.wav", sampleRate, waveForm); //file name can be changed but keep extension .wav 
    waveForm.clear(); //if using vectors 
    return 0;
}
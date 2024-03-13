
//------- Imports -------
#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 

using namespace::std;

//------- Global ---------

string fileName = "anotherbrickinthewall.txt";

int samplesPerNote = 300;// dont touch pls will break
float noteDuration = 0.13;// dont touch pls will break

int sampleRate = samplesPerNote / noteDuration; // samples per second, select value which provides good quality sound  
float dt = 1.0 / sampleRate; // time between samples 

float pi = 3.14159;

std::vector<int> waveForm;

//------- Functions ---------

//This function reads the frequincy values from the name of a text file and returns a vector of them
vector<float> readFile(string fileName) {
    ifstream openedFile;
    openedFile.open(fileName);
    vector<float> frequincys; //inialises the vector to be returned
    string line;              //inialises the varable to store the value read
    //This loop goes through every line of the text file and extracts the frequincy
    while (getline(openedFile,line)) {
        frequincys.push_back(stof(line));
    }
    return(frequincys);
}


// This fuction takes the current note and sample of that note and returns the amplatude
float calculateSine(int currentNote, int currentSample) {
    int numOfHarmonics = 4;     // The number of harmonics to add
    int harmonicMultiplyer = 1; // The inital number for the harmonics
    float output = 0;           // initalising the output
    // This loop adds each harmonic to the output varable 
    for (int harmonicNum = 0; harmonicNum < numOfHarmonics; harmonicNum += 1) {
        output = output + sin(2 * 3.14159 * (currentNote / harmonicMultiplyer) * currentSample * dt);
        harmonicMultiplyer = harmonicMultiplyer * 2;
    }
    
    return(output);
}


//------- Main ---------
int main() {
    //Reads values from the filename inputed
    vector<float> rawWaveForm = readFile(fileName);

    //loops for the number of notes/frequinces read from the file/in the vector
    for (int currentNote = 0; currentNote < rawWaveForm.size(); currentNote += 1) {
        //loops for the number of samples each note contains
        for (int currentSample = 0; currentSample < samplesPerNote; currentSample += 1) {
            //checks if it is writting the first 80 samples and if so adds the attack to the amplatude
            if (currentSample < 80) {
                waveForm.push_back(static_cast<int>((633 * currentSample * dt) * calculateSine(rawWaveForm[currentNote],currentSample)));
            }
            else {
                waveForm.push_back(static_cast<int>((200/(currentSample * dt)) * calculateSine(rawWaveForm[currentNote], currentSample)));
            }
        }
    }


    MakeWavFromVector("tone1.wav", sampleRate, waveForm);
    waveForm.clear(); 
    return 0;
}

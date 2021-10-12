#include <iostream>
#include <string>

#include <vector>

enum NoteName {
  DO = 1,
  RE,
  MI = 4,
  FA = 8,
  SOL = 16,
  LA = 32,
  SI = 64
};

bool InputNoteCorrectness(std::string &notes) {
  for (char note: notes) {
    if (!(note >= '1' && note <= '7')) {
      return false;
    }
  }
  return true;
}

void TranslatingIntoBitMask(std::string &inputNotes, std::vector<int> &notes) {
  for (int i = 0, derivative; i < inputNotes.size(); ++i) {
    derivative = 1;
    for (int j = 1; j < (inputNotes[i]-'0'); ++j) {
      derivative <<= 1;
    }
    notes.push_back(derivative);
  }
}

void NoteInput(std::vector<int> &listOfNotes) {

  std::string inputNotes;
  std::cout << "Input combination of notes:" << std::endl;
  for (int i = 0; i < 12; ++i) {
    std::cin >> inputNotes;
    if (!InputNoteCorrectness(inputNotes)) {
      i--;
      std::cout << "You inputted wrong note number! Try again." << std::endl;
    } else {
      TranslatingIntoBitMask(inputNotes, listOfNotes);
    }
  }
}

void BeautyOutput(int note) {
  if (note == DO) {
    std::cout << "Do";
  } else if (note == RE) {
    std::cout << "Re";
  } else if (note == MI) {
    std::cout << "Mi";
  } else if (note == FA) {
    std::cout << "Fa";
  } else if (note == SOL) {
    std::cout << "Sol";
  } else if (note == LA) {
    std::cout << "La";
  } else if (note == SI) {
    std::cout << "Si";
  }
}

void NoteOutput(std::vector<int> &listOfNotes) {
  std::cout << "\n The song: " << std::endl;
  for (int i = 0; i < listOfNotes.size(); ++i) {
    if (i != 0) {
      std::cout << " ";
    }
    BeautyOutput(listOfNotes[i]);
  }
}

int main() {
  std::cout << "--- Mechanical Piano ---" << std::endl;
  std::vector<int> listOfNotes;
  NoteInput(listOfNotes);
  NoteOutput(listOfNotes);
  return 0;
}

#include <iostream>
#include <string>

enum NoteName {
  DO,
  RE,
  MI,
  FA,
  SOL,
  LA,
  SI
};

bool InputNotesCorrectness(std::string &notes) {
  if (notes.size() != 3) {
    return false;
  } else {
    for (char note: notes) {
      if (!(note >= '1' && note <= '7')) {
        return false;
      }
    }
    return true;
  }
}

void NoteInput(std::string &listOfNotes) {
  std::string inputNotes;
  std::cout << "Input combination of notes:" << std::endl;
  for (int i = 0; i < 12; ++i) {
    std::cin >> inputNotes;
    if (!InputNotesCorrectness(inputNotes)) {
      i--;
      std::cout << "You inputted wrong note number! Try again." << std::endl;
    } else {
      listOfNotes += inputNotes;
    }
  }
}

void NoteOutput(std::string &listOfNotes){
  std::cout<<"\n The song: "<<std::endl;
  for (int i = 0, num; i < listOfNotes.size(); ++i) {
    num=((listOfNotes[i])-'0')-1;
    if (i!=0){
      std::cout<<" ";
    }
    if (num==DO){
      std::cout<<"Do";
    }else if (num==RE){
      std::cout<<"Re";
    }
    else if (num==MI){
      std::cout<<"Mi";
    }
    else if (num==FA){
      std::cout<<"Fa";
    }
    else if (num==SOL){
      std::cout<<"Sol";
    }
    else if (num==LA){
      std::cout<<"La";
    }
    else if (num==SI){
      std::cout<<"Si";
    }
  }
}

int main() {
  std::cout << "--- Mechanical Piano ---" << std::endl;
  std::string listOfNotes;
  NoteInput(listOfNotes);
  NoteOutput(listOfNotes);
  return 0;
}

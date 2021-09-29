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

void NotePrinting(NoteName note){
  if (note==DO){
    std::cout<<"Do";
  }else if (note==RE){
    std::cout<<"Re";
  }
  else if (note==MI){
    std::cout<<"Mi";
  }
  else if (note==FA){
    std::cout<<"Fa";
  }
  else if (note==SOL){
    std::cout<<"Sol";
  }
  else if (note==LA){
    std::cout<<"La";
  }
  else if (note==SI){
    std::cout<<"Si";
  }
}

void NoteOutput(std::string &listOfNotes){
  NoteName note;
  std::cout<<"\n The song: "<<std::endl;
  for (int i = 0, num; i < listOfNotes.size(); ++i) {
    num=((listOfNotes[i])-'0')-1;
    if (i!=0){
      std::cout<<" ";
    }
    if (num==0){
      note=DO;
    }else if(num==1){
      note=RE;
    }
    else if(num==2){
      note=MI;
    }
    else if(num==3){
      note=FA;
    }
    else if(num==4){
      note=SOL;
    }
    else if(num==5){
      note=LA;
    }
    else if(num==6){
      note=SI;
    }
    NotePrinting(note);
  }
}

int main() {
  std::cout << "--- Mechanical Piano ---" << std::endl;
  std::string listOfNotes;
  NoteInput(listOfNotes);
  NoteOutput(listOfNotes);
  return 0;
}

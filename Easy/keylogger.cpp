// <summary>
// src : https://open.kattis.com/problems/keylogger
// </summary>

#include <iostream>
#include <unordered_map>
#include <list>
#include <cstring>

using namespace std;

class StringBasedOnList{
    list<char> chars;
    
    public:
        StringBasedOnList(){
            chars = list<char>();
        }

        void insert(char new_char){
            chars.push_back(new_char);
        }

        void remove(){
            if(chars.size() > 0){
                chars.pop_back();
            }
        }

        void display_string(){
            for(auto const& i : chars){
                cout << i;
            }
        }
};

typedef unordered_map<string, string> SoundToKeyMap;
typedef StringBasedOnList CustomString;

bool is_shift_down = false;
bool is_caps = false;

void init_sound_to_key_map(SoundToKeyMap* map){
    map->insert(make_pair("clank","a"));
    map->insert(make_pair("bong","b"));
    map->insert(make_pair("click","c"));
    map->insert(make_pair("tap","d"));
    map->insert(make_pair("poing","e"));
    map->insert(make_pair("clonk","f"));
    map->insert(make_pair("clack","g"));
    map->insert(make_pair("ping","h"));
    map->insert(make_pair("tip","i"));
    map->insert(make_pair("cloing","j"));
    map->insert(make_pair("tic","k"));
    map->insert(make_pair("cling","l"));
    map->insert(make_pair("bing","m"));
    map->insert(make_pair("pong","n"));
    map->insert(make_pair("clang","o"));
    map->insert(make_pair("pang","p"));
    map->insert(make_pair("clong","q"));
    map->insert(make_pair("tac","r"));
    map->insert(make_pair("boing","s"));
    map->insert(make_pair("boink","t"));
    map->insert(make_pair("cloink","u"));
    map->insert(make_pair("rattle","v"));
    map->insert(make_pair("clock","w"));
    map->insert(make_pair("toc","x"));
    map->insert(make_pair("clink","y"));
    map->insert(make_pair("tuc","z"));
    map->insert(make_pair("whack"," "));
    map->insert(make_pair("bump","caps"));
    map->insert(make_pair("pop","del"));
    map->insert(make_pair("dink","shold"));
    map->insert(make_pair("thumb","srel"));
}

bool is_shift(){
    return is_shift_down ^ is_caps;
}

void receive_input(CustomString* output_string, SoundToKeyMap* sound_to_key_map, string new_sound){
    try {
        string value = sound_to_key_map->at(new_sound);
        if (value != "caps" && value != "del" && value != "shold" && value != "srel"){
            output_string->insert(is_shift()? toupper(value[0]) : value[0]);
            return;
        }

        if(value == "caps"){
            is_caps = !is_caps;
            return;
        }

        if(value == "shold"){
            is_shift_down = true;
            return;
        }

        if(value == "srel"){
            is_shift_down = false;
            return;
        }

        if(value == "del"){
            output_string->remove();
        }
    }catch (out_of_range e){
        return;
    }
}

int main(){
    
    SoundToKeyMap sound_to_key_map;
    CustomString output_string = CustomString();

    init_sound_to_key_map(&sound_to_key_map);

    int no_of_inputs;
    cin >> no_of_inputs;

    for(int i = 0; i < no_of_inputs; i++){
        string new_sound;
        cin >> new_sound;
        receive_input(&output_string, &sound_to_key_map, new_sound);
    }

    output_string.display_string();

    return 0;
}
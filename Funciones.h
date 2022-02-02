#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <map>
#include <string>

typedef sf::Texture texture;
typedef sf::SoundBuffer sound;
typedef sf::Font font;
typedef string key;

texture &getTexture_or_insert(std::map<key, texture> &M, string &url) {
	if(M.find(url) == M.end()) {
		texture t;
		t.loadFromFile(url);
		M[url] = t;
	}
	return M.find(url)->second;
}

sound &getBuffer_or_insert(std::map<key, sound> &M, string &url) {
	if(M.find(url) == M.end()) {
		sound s;
		s.loadFromFile(url);
		M[url] = s;
	}
	return M.find(url)->second;
}

font &getFont_or_insert(std::map<key, font> &M, string &url) {
	if(M.find(url) == M.end()) {
		font f;
		f.loadFromFile(url);
		M[url] = f;
	}
	return M.find(url)->second;
}

#endif

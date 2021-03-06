#include "debug.h"

DEFINE_PLUGIN(DebugLines);

/*
				1  2  3  4  5
				6  7  8  9 10
				11 12 13 14 15
				16 17 18 19 20
				21 22 23 24 25
*/

vec2 points[] = {
	{0.0f,0.8f}, {0.2f,0.8f}, {0.4f,0.8f}, {0.6f,0.8f}, {0.8f,0.8f},
	{0.0f,0.6f}, {0.2f,0.6f}, {0.4f,0.6f}, {0.6f,0.6f}, {0.8f,0.6f},
	{0.0f,0.4f}, {0.2f,0.4f}, {0.4f,0.4f}, {0.6f,0.4f}, {0.8f,0.4f},
	{0.0f,0.2f}, {0.2f,0.2f}, {0.4f,0.2f}, {0.6f,0.2f}, {0.8f,0.2f},
	{0.0f,0.0f}, {0.2f,0.0f}, {0.4f,0.0f}, {0.6f,0.0f}, {0.8f,0.0f}
};

int letter_paths[][30] = {
	{/*!*/ 3,13, 18,23, 0},
	{/*"*/ 3,8, 4,9, 0},
	{/*#*/ 2,22, 4,24, 6,10, 16,20, 0},
	{/*$*/ 10,4, 4,2, 2,6, 6,12, 12,14, 14,20, 20,24, 24,22, 22,16, 3,23, 0},
	{/*%*/ 1,2, 2,7, 7,6, 6,1, 5,21, 19,20, 20,25, 25,24, 24,19, 0},
	{/*&*/ 20,24, 24,22, 22,16, 16,9, 9,3, 3,7, 7,25, 0},
	{/*'*/ 3,8, 0},
	{/*(*/ 4,8, 8,18, 18,24, 0},
	{/*)*/ 2,8, 8,18, 18,22, 0},
	{/***/ 2,14, 4,12, 0},
	{/*+*/ 12,14, 8,18, 0},
	{/*,*/ 13,18, 18,22, 0},
	{/*-*/ 12,14, 0},
	{/*.*/ 18,23, 0},
	{/*/*/ 22,4, 0},
	{/*0*/ 2,4, 4,10, 10,20, 20,24, 24,22, 22,16, 16,6, 6,2, 4,22, 0},
	{/*1*/ 7,3, 3,23, 22,24, 0},
	{/*2*/ 6,2, 2,4, 4,10, 10,21, 21,25, 0},
	{/*3*/ 6,2, 2,4, 4,10, 10,14, 12,14, 14,20, 20,24, 24,22, 22,16, 0},
	{/*4*/ 1,11, 11,15, 5,25, 0},
	{/*5*/ 5,1, 1,11, 11,14, 14,20, 20,24, 24,22, 22,16, 0},
	{/*6*/ 10,4, 4,2, 2,6, 6,16, 16,22, 22,24, 24,20, 20,14, 14,11, 0},
	{/*7*/ 1,5, 5,21, 0},
	{/*8*/ 2,6, 6,12, 12,14, 12,16, 16,22, 22,24, 24,20, 20,14, 14,10, 10,4, 4,2, 0},
	{/*9*/ 15,12, 12,6, 6,2, 2,4, 4,10, 10,20, 20,24, 24,22, 22,16, 0},
	{/*:*/ 3,8, 18,23, 0},
	{/*;*/ 3,8, 18,22, 0},
	{/*<*/ 9,12, 12,19, 0},
	{/*=*/ 7,9, 17,19, 0},
	{/*>*/ 7,14, 14,17, 0},
	{/*?*/ 6,2, 2,4, 4,10, 10,13, 18,23, 0},
	{/*@*/  0},
	{/*A*/ 21,11, 11,3, 3,15, 15,25, 11,15, 0},
	{/*B*/ 1,4, 4,10, 10,14, 14,20, 20,24, 24,21, 21,1, 11,14, 0},
	{/*C*/ 4,2, 2,6, 6,16, 16,22, 22,24, 0},
	{/*D*/ 1,4, 4,10, 10,20, 20,24, 24,21, 21,1, 0},
	{/*E*/ 5,1, 1,21, 21,25, 11,14, 0},
	{/*F*/ 5,1, 1,21, 11,13, 0},
	{/*G*/ 10,4, 4,2, 2,6, 6,16, 16,22, 22,24, 24,20, 20,15, 15,13, 0},
	{/*H*/ 1,21, 5,25, 11,15, 0},
	{/*I*/ 2,4, 3,23, 22,24, 0},
	{/*J*/ 1,5, 4,19, 19,23, 23,22, 22,16, 0},
	{/*K*/ 1,21, 11,4, 11,24, 0},
	{/*L*/ 1,21, 21,25, 0},
	{/*M*/ 21,1, 1,13, 13,5, 25,5, 0},
	{/*N*/ 21,1, 1,25, 25,5, 0},
	{/*O*/ 2,4, 4,10, 10,20, 20,24, 24,22, 22,16, 16,6, 6,2, 0},
	{/*P*/ 1,4, 4,10, 10,14, 14,11, 1,21, 0},
	{/*Q*/ 2,4, 4,10, 10,20, 20,24, 24,22, 22,16, 16,6, 6,2, 19,25, 0},
	{/*R*/ 1,4, 4,10, 10,14, 14,11, 1,21, 12,24, 0},
	{/*S*/ 10,4, 4,2, 2,6, 6,12, 12,14, 14,20, 20,24, 24,22, 22,16, 0},
	{/*T*/ 1,5, 3,23, 0},
	{/*U*/ 1,16, 16,22, 22,24, 24,20, 20,5, 0},
	{/*V*/ 1,23, 23,5, 0},
	{/*W*/ 1,21, 21,13, 13,25, 25,5, 0},
	{/*X*/ 1,25, 5,21, 0},
	{/*Y*/ 1,13, 5,13, 13,23, 0},
	{/*Z*/ 1,5, 5,21, 21,25, 0},
	{/*[*/ 4,3, 3,23, 23,24, 0},
	{/*\\*/ 2,24, 0},
	{/*]*/ 2,3, 3,23, 23,22, 0},
	{/*^*/ 7,3, 3,9, 0},
	{/*_*/ 21,25, 0},
	{/*`*/ 8,2, 0},
	// {/*a*/ 25,20, 20,14, 14,12, 12,16, 16,22, 22,24, 24,20, 0},
	// {/*b*/ 1,21, 16,12, 12,14, 14,20, 20,24, 24,21, 0},
	// {/*c*/ 15,12, 12,16, 16,22, 22,25, 0},
	// {/*d*/ 5,25, 20,14, 14,12, 12,16, 16,22, 22,25, 0},
	// {/*e*/ 16,20, 20,14, 14,12, 12,16, 16,22, 22,24, 0},
	// {/*f*/ 22,7, 7,3, 3,4, 11,14, 0},
	// {/*g*/ 14,12, 12,16, 16,22, 22,24, 24,20, 20,18, 0},
	// {/*h*/ 1,21, 16,12, 12,14, 14,20, 20,25, 0},
	// {/*i*/ 3,8, 13,23, 0},
	// {/*j*/ 3,8, 13,18, 18,22, 22,16, 0},
	// {/*k*/ 1,21, 16,15, 16,25, 0},
	// {/*l*/ 3,23, 0},
	// {/*m*/ 21,16, 16,12, 12,18, 18,14, 14,20, 20,25, 0},
	// {/*n*/ 21,16, 16,12, 12,14, 14,20, 20,25, 0},
	// {/*o*/ 16,12, 12,14, 14,20, 20,24, 24,22, 22,16, 0},
	// {/*p*/ 21,11, 11,14, 14,20, 20,16, 0},
	// {/*q*/ 15,25, 20,16, 16,12, 12,15, 0},
	// {/*r*/ 11,21, 16,12, 12,15, 0},
	// {/*s*/ 15,12, 12,16, 16,20, 20,24, 24,21, 0},
	// {/*t*/ 8,23, 11,15, 0},
	// {/*u*/ 11,16, 16,22, 22,24, 24,20, 20,15, 0},
	// {/*v*/ 11,23, 23,15, 0},
	// {/*w*/ 11,21, 21,18, 18,25, 25,15, 0},
	// {/*x*/ 11,25, 15,21, 0},
	// {/*y*/ 11,17, 17,19, 15,19, 19,23, 23,22, 0},
	// {/*z*/ 11,15, 15,21, 21,25, 0},
	
	{/*a*/ 7,9, 9,15, 15,25, 20,24, 24,22, 22,16, 16,12, 12,15, 0},
	{/*b*/ 1,21, 11,7, 7,9, 9,15, 15,20, 20,24, 24,21, 0},
	{/*c*/ 10,7, 7,11, 11,16, 16,22, 22,25, 0},
	{/*d*/ 5,25, 15,9, 9,7, 7,11, 11,16, 16,22, 22,25, 0},
	{/*e*/ 11,15, 15,9, 9,7, 7,11, 11,16, 16,22, 22,24, 24,20, 0},
	{/*f*/ 22,7, 7,3, 3,4, 11,14, 0},
	{/*g*/ 20,17, 17,11, 11,7, 7,9, 9,15, 15,20, 20,24, 24,22,  0},
	{/*h*/ 1,21, 11,7, 7,9, 9,15, 15,25, 0},
	{/*i*/ 3,8, 13,23, 0},
	{/*j*/ 3,8, 13,18, 18,22, 22,16, 0},
	{/*k*/ 1,21, 16,10, 16,25, 0},
	{/*l*/ 3,23, 0},
	{/*m*/ 21, 11, 11,7, 7,13, 13,18, 13,9, 9,15, 15,25, 0},
	{/*n*/ 21,11, 11,7, 7,9, 9,15, 15,25, 0},
	{/*o*/ 16,11, 11,7, 7,9, 9,15, 15,20, 20,24, 24,22, 22,16, 0},
	{/*p*/ 6,21, 11,7, 7,9, 9,15, 15,19, 19,16, 0},
	{/*q*/ 10,25, 15,9, 9,7, 7,11, 11,17, 17,20, 0},
	{/*r*/ 6,21, 11,7, 7,10, 0},
	{/*s*/ 10,7, 7,11, 11,20, 20,24, 24,21, 0},
	{/*t*/ 3,23, 6,10, 0},
	{/*u*/ 6,16, 16,22, 22,24, 24,20, 20,10, 0},
	{/*v*/ 6,23, 23,10, 0},
	{/*w*/ 6,21, 21,18, 18,25, 25,10, 0},
	{/*x*/ 6,25, 10,21, 0},
	{/*y*/ 6,11, 11,17, 17,19, 19,15, 10,20, 20,24, 24,22, 0},
	{/*z*/ 6,10, 10,21, 21,25, 0},
	
	{/*{*/ 4,3, 3,8, 8,12, 12,18, 18,23, 23,24, 0},
	{/*|*/ 3,23, 0},
	{/*}*/ 2,3, 3,8, 8,14, 14,18, 18,23, 23,22, 0},
	{/*~*/ 6,12, 12,8, 8,14, 0}
};


const vec2 let_size = vec2(0.02f, 0.04f);

void DebugLines::draw(vec2 pos, char let) {
	if (let < '!' or let > '~') return;
	int let_index = let - '!';
	int i = 0;
	while (letter_paths[let_index][i] != 0) {
		draw(points[letter_paths[let_index][i]-1] * let_size + pos,
			points[letter_paths[let_index][i+1]-1] * let_size + pos);
		i += 2;
	}
}

void DebugLines::draw(vec2 pos, const string& text) {
	vec2 curpos = pos;
	for (char let : text) {
		if (let == '\n') {
			curpos.x = pos.x;
			curpos.y -= let_size.y;
		} else {
			draw(curpos, let);
			curpos.x += let_size.x;
		}
	}
}

DebugLines* debuglines = nullptr;

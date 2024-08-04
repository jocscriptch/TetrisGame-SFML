#include "Parts.h"

// aca se pintan los bloques del tetris que caen de arriba

Parts::Parts()
{
	parts = {
			 {
			   {1,1},
			   {1,1}},

			 {
			  {0,0,0,0,0},
			  {0,0,1,0,0},
			  {0,0,1,1,0},
			  {0,0,0,1,0},
			  {0,0,0,0,0}
			 },

			 {
			  {0,0,0,0,0},
			  {0,0,0,1,0},
			  {0,0,1,1,0},
			  {0,0,1,0,0},
			  {0,0,0,0,0}
			 },

			 {
			  {0,0,0,0,0},
			  {0,0,1,1,0},
			  {0,0,1,0,0},
			  {0,0,1,0,0},
			  {0,0,0,0,0}
			 },

			 {
			  {0,0,0,0,0},
			  {0,1,1,0,0},
			  {0,0,1,0,0},
			  {0,0,1,0,0},
			  {0,0,0,0,0}
			 },

			 {
			  {0,0,0,0,0},
			  {0,0,1,0,0},
			  {0,0,1,1,0},
			  {0,0,1,0,0},
			  {0,0,0,0,0}
			 },

			 {
			  {0,0,1,0},
			  {0,0,1,0},
			  {0,0,1,0},
			  {0,0,1,0}
			 }
	};
}
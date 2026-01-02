//PPP3/ch03_game_loop_console_ship_phase_1/ch03_game_loop_console_ship_phase_1.cpp

// - Ship wraps around canvas borders 0 <= x < canvas_width
//                                 0 <= y < canvas_height
// - Ship angle is normalized to 2.0 * pi
// - Ship speed is clamped to max_speed => speed <= max_speed

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <conio.h>
#include <numbers>

const bool SYSTEM_CLS = false;
const double TWO_PI = 2.0 * std::numbers::pi;

struct ShipState
{
	double              x{ 0 };
	double              y{ 0 };
	double             vx{ 0 };
	double             vy{ 0 };
	double t_acceleration{ 0.12 };
	double          speed{ 0 };
	double          angle{ std::numbers::pi * 0.5 }; // Up 
	double      turn_rate{ 0.06 }; // ~3.4 degrees
	double      max_speed{ 12 };
	double intertial_drag{ 0.001 };
};

struct GameState
{
	double  canvas_width{ 80 };
	double canvas_height{ 20 };
	double       delta_v{ 1 };
	bool         is_quit{ false };
};

int main()
{
	

	GameState gs;
	ShipState ship{ .x = (gs.canvas_width * 0.5) };
	size_t ticks{ 0 };

	while (!gs.is_quit)
	{	
		if(_kbhit())
		{
			char input_key{ 0 };
			input_key = _getch();

			switch (input_key)
			{
			case 'q':
			{
				gs.is_quit = true;
				break;
			}
			case 'w':
			{
				ship.vx += std::cos(ship.angle) * ship.t_acceleration;
				ship.vy += std::sin(ship.angle) * ship.t_acceleration;
				break;
			}
			case 'a':
			{
				ship.angle += ship.turn_rate;
				break;
			}
			case 'd':
			{
				ship.angle -= ship.turn_rate;
				break;
			}
			default:
				break;
			}
		}

		ship.vx *= (1.0 - ship.intertial_drag);
		ship.vy *= (1.0 - ship.intertial_drag);

		while (ship.angle < 0)
			ship.angle += TWO_PI;

		while (ship.angle >= TWO_PI)
			ship.angle -= TWO_PI;
		
		ship.speed = std::sqrt(ship.vx * ship.vx + ship.vy * ship.vy);
		if (ship.speed > ship.max_speed && ship.speed > 0)
		{
			double scale = ship.max_speed / ship.speed;
			ship.vx *= scale;
			ship.vy *= scale;
		}

		ship.x += ship.vx;
		ship.y += ship.vy;

		while (ship.x < 0)
			ship.x += gs.canvas_width;

		while (ship.x >= gs.canvas_width)
			ship.x -= gs.canvas_width;

		while (ship.y < 0)
			ship.y += gs.canvas_height;

		while (ship.y >= gs.canvas_height)
			ship.y -= gs.canvas_height;

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
		ticks++;

		// Only display output
		if (ticks % 20 == 0)
		{
			double d = ship.angle * 180 / std::numbers::pi;
			if (SYSTEM_CLS) system("cls");
			std::cout << "x: " << ship.x << ", y: " << ship.y << ", vx: " 
				<< ship.vx << ", vy: " << ship.vy << ", angle: " << d << "\n\n";
		}
	}

	return 0;
}
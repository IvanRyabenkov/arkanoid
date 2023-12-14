#include <SFML/Graphics.hpp>
#include <time.h>


using namespace sf;

// класс для создания элементов игры
class Objects {
public:
	Sprite background, gamename, play_button, settings, exit_button, configure_controls, tips_button, back, elems_of_control, selection_line, levels_inscription,
		level_button[8], players_platform, ball, controls_button, AD_elements, arrow_elements, begin_button, block[18], pblock, platform_killer,
		win, begin_again, sledur, back_to_menu, life[3], the_end, pause_button, pause_inscription, continue_button;
	RectangleShape line;
};

// класс для вызова элементов игры
class Boolean {
public:
	bool menu = true, setting = false, show_tips = true, show_settings = false, ad = true, game = false,
		game_process = false, begin_game = false, play = false, mball = true, pusklever[8], rblock[18],
		pob = false, blv[8], death = false, pause = false;


		

	Boolean() {
		for (int i = 0; i < 8; i++)
			pusklever[i] = false;

		for (int i = 0; i < 18; i++)
			rblock[i] = false;

		blv[0] = true;
		for (int i = 1; i < 8; i++)
			blv[i] = false;
	}
};

int main()
{
	srand(time(0));

	RenderWindow window(VideoMode(1200, 700), "Arkanoid");

	Objects o;
	Boolean b;

	//создание текстур, отвечающих за соответствующие элементы игры
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18,
		t19, t20, t21, t22, t23, t24, t25, t26, t27, t28;
	t1.loadFromFile("background.png");
	t2.loadFromFile("naz.png");
	t3.loadFromFile("play_button.png");
	t4.loadFromFile("settings.png");
	t5.loadFromFile("exit_button.png");
	t6.loadFromFile("configure_controls.png");
	t7.loadFromFile("tips_button.png");
	t8.loadFromFile("back.png");
	t9.loadFromFile("elems_of_control.png");
	t10.loadFromFile("selection_line.png");
	t11.loadFromFile("levels_inscription.png");
	t12.loadFromFile("level_button.png");
	t13.loadFromFile("players_platform.png");
	t14.loadFromFile("ball.png");
	t15.loadFromFile("controls_button.png");
	t16.loadFromFile("AD_elements.png");
	t17.loadFromFile("arrow_elements.png");
	t18.loadFromFile("begin_button.png");
	t19.loadFromFile("block.png");
	t20.loadFromFile("platform_killer.png");
	t21.loadFromFile("win.png");
	t22.loadFromFile("begin_again.png");
	t23.loadFromFile("sledur.png");
	t24.loadFromFile("back_to_menu.png");
	t25.loadFromFile("the_end.png");
	t26.loadFromFile("pause_button.png");
	t27.loadFromFile("pause_inscription.png");
	t28.loadFromFile("continue_button.png");

	// добавление картинок элементов игры
	o.background.setTexture(t1);
	o.gamename.setTexture(t2);
	o.gamename.setPosition(350, 44); //положение названия игры
	o.play_button.setTexture(t3);
	o.play_button.setPosition(50, 350); //положение кнопки начала игры
	o.settings.setTexture(t4);
	o.settings.setPosition(550, 350); // положение кнопки настроек
	o.exit_button.setTexture(t5);
	o.exit_button.setPosition(400, 525); // положение кнопки выхода

	o.configure_controls.setTexture(t6);
	o.configure_controls.setPosition(200, 175);
	o.tips_button.setTexture(t7);
	o.tips_button.setTextureRect(IntRect(890, 0, 808, 90));
	o.tips_button.setPosition(220, 350); // положение кнопки выключения/отключения подсказок
	o.back.setTexture(t8);

	o.elems_of_control.setTexture(t9);
	o.elems_of_control.setPosition(320, 175);
	o.selection_line.setTexture(t10);
	int px = 320; // элемент для выбора управления

	o.levels_inscription.setTexture(t11);
	o.levels_inscription.setPosition(300, 44); //положение для уровней игры
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++) {
			o.level_button[j * 4 + i].setTexture(t12);
			o.level_button[j * 4 + i].setTextureRect(IntRect(0, 0, 160, 160));
			o.level_button[j * 4 + i].setPosition(150 + 219 * i, 219 + 219 * j);
		}
	o.level_button[0].setTextureRect(IntRect(0, 160, 160, 160));

	//создание платформы игрока и мяча
	o.players_platform.setTexture(t13);
	o.ball.setTexture(t14);
	int kx = 1, ky = 1;

	// добавление картинок элементов игры
	o.controls_button.setTexture(t15);
	o.controls_button.setPosition(50, 499);
	o.AD_elements.setTexture(t16);
	o.AD_elements.setPosition(740, 481);
	o.arrow_elements.setTexture(t17);
	o.arrow_elements.setPosition(740, 481);
	o.begin_button.setTexture(t18);
	o.begin_button.setPosition(900, 595);

	o.line.setSize(Vector2f(1200, 1));
	o.line.setFillColor(Color::White);
	o.line.setPosition(0, 88);

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++) {
			o.block[j * 6 + i].setTexture(t19);
			o.block[j * 6 + i].setTextureRect(IntRect(0, 0, 140, 26));
		}
	o.pblock.setTexture(t19);
	o.pblock.setTextureRect(IntRect(280, 0, 140, 26));
	int pbx = 1, db = 0, lv = 0;

	o.platform_killer.setTexture(t20);
	o.platform_killer.setPosition(1200, 88);
	int pl = rand() % 1000;

	o.win.setTexture(t21);
	o.win.setPosition(400, 175);
	o.begin_again.setTexture(t22);
	o.begin_again.setPosition(150, 306);
	o.sledur.setTexture(t23);
	o.sledur.setPosition(350, 411);
	o.back_to_menu.setTexture(t24);
	o.back_to_menu.setPosition(150, 525);
	o.the_end.setTexture(t25);
	o.the_end.setPosition(350, 175);

	for (int i = 0; i < 3; i++) {
		o.life[i].setTexture(t14);
		o.life[i].setPosition(10 + 100 * i, 9);
		o.life[i].setScale(0.9, 0.9);
	}
	int lf = 3;

	o.pause_button.setTexture(t26);
	o.pause_button.setPosition(1080, 5);
	o.pause_inscription.setTexture(t27);
	o.pause_inscription.setPosition(400, 175);
	o.continue_button.setTexture(t28);
	o.continue_button.setPosition(350, 411);
	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left) { //условие нажатия на левую кнопку мыши
					if (b.play && b.mball)
						b.mball = false;

					Vector2i pos = Mouse::getPosition(window); //получение позиции курсора на экране

					if (b.menu) {
						// выполнение действий в зависимости от нажатия левой кнопкой мыши на определенную область экрана
						if (pos.x >= 400 && pos.x <= 748 &&
							pos.y >= 481 && pos.y <= 622)
							window.close();

						if (pos.x >= 550 && pos.x <= 1164 &&
							pos.y >= 306 && pos.y <= 449) {
							b.menu = false;
							b.setting = true;

							o.back.setPosition(220, 525); //позиция кнопки "назад"
						}

						if (pos.x >= 50 && pos.x <= 433 &&
							pos.y >= 350 && pos.y <= 483) { // если нажата кнопка играть, то переходим в окно игры к выбору уровня
							b.menu = false;
							b.game = true;

							o.back.setPosition(150, 604);
						}
					}

					else if (b.setting) {
						if (pos.x >= 220 && pos.x <= 465 &&
							pos.y >= 525 && pos.y <= 621) {
							b.menu = true;
							b.setting = false;
						}
						// нажатие на кнопку включения/выключения подсказок
						if (pos.x >= 220 && pos.x <= 1028 &&
							pos.y >= 350 && pos.y <= 439 && b.show_tips) {
							b.show_tips = false;

							o.tips_button.setTextureRect(IntRect(0, 0, 890, 89));
							o.tips_button.setPosition(180, 350);
						}

						else if (pos.x >= 180 && pos.x <= 1070 &&
							pos.y >= 350 && pos.y <= 439 && !b.show_tips) {
							b.show_tips = true;

							o.tips_button.setTextureRect(IntRect(890, 0, 808, 89));
							o.tips_button.setPosition(220, 350);
						}

						if (pos.x >= 200 && pos.x <= 1022 &&
							pos.y >= 175 && pos.y <= 272) {
							b.setting = false;
							b.show_settings = true;
						}
					}

					else if (b.show_settings) { // условие того, что показано окно с выбором управления
						// в зависимости от нажатия на определенный элемент для выбора управления, перемещается платформа, показывающая выбранное управление
						if (pos.x >= 583 && pos.x <= 847 &&
							pos.y >= 175 && pos.y <= 330 &&
							b.ad)
							b.ad = false;

						if (pos.x >= 320 && pos.x <= 583 &&
							pos.y >= 175 && pos.y <= 330 &&
							!b.ad)
							b.ad = true;

						if (pos.x >= 220 && pos.x <= 465 &&
							pos.y >= 525 && pos.y <= 621) {
							b.setting = true;
							b.show_settings = false;
						}
					}

					else if (b.game) {
						// выход из окна игры в меню
						if (pos.x >= 150 && pos.x <= 395 &&
							pos.y >= 604 && pos.y <= 700) {
							b.menu = true;
							b.game = false;
						}

						for (int i = 0; i < 4; i++)
							for (int j = 0; j < 2; j++)
								if (pos.x >= 150 + 250 * i && pos.x <= 310 + 250 * i &&
									pos.y >= 219 + 219 * j && pos.y <= 379 + 219 * j &&
									b.blv[j * 4 + i]) {
									b.game = false;
									b.pusklever[j * 4 + i] = true;
									lv = j * 4 + i;

									if (b.show_tips) {
										b.game_process = true;

										//Координаты игрока и мяча в подсказке
										o.players_platform.setPosition(400, 438);
										o.ball.setPosition(510, 363);
									}

									else
										b.begin_game = true;
								}
					}

					else if (b.game_process) {
						if (pos.x >= 150 && pos.x <= 395 &&
							pos.y >= 604 && pos.y <= 700) {
							b.game = true;
							b.game_process = false;
						}

						if (pos.x >= 900 && pos.x <= 1145 &&
							pos.y >= 595 && pos.y <= 691) {
							b.game_process = false;
							b.begin_game = true;
						}
					}

					else if (b.pob || b.death || b.pause) {
						if (pos.x >= 150 && pos.x <= 615 &&
							pos.y >= 306 && pos.y <= 388) {
							b.pob = false;
							b.begin_game = true;

							for (int i = 0; i < 6; i++)
								for (int j = 0; j < 3; j++)
									o.block[j * 6 + i].setPosition(25 + 200 * i, 88 + 88 * (j + 1));
							db = 0;
						}

						if (pos.x >= 350 && pos.x <= 1062 &&
							pos.y >= 411 && pos.y <= 497 && lv < 7 && !b.death && !b.pause) {
							b.pob = false;
							b.begin_game = true;

							b.pusklever[lv] = false;
							b.pusklever[lv + 1] = true;
							lv++;

							for (int i = 0; i < 6; i++)
								for (int j = 0; j < 3; j++)
									o.block[j * 6 + i].setPosition(25 + 200 * i, 88 + 88 * (j + 1));
							db = 0;
						}

						if (pos.x >= 150 && pos.x <= 720 &&
							pos.y >= 525 && pos.y <= 588) {
							b.pob = false;
							b.menu = true;
							b.play = false;
							b.death = false;
							b.pause = false;

							for (int i = 0; i < 8; i++)
								b.pusklever[i] = false;
						}

						if (pos.x >= 350 && pos.x <= 894 &&
							pos.y >= 411 && pos.y <= 491 && b.pause) {
							b.pause = false;
							b.mball = true;
						}
					}

					else if (b.play)
						if (pos.x >= 1080 && pos.x <= 1187 &&
							pos.y >= 4 && pos.y <= 96)
							b.pause = true;
				}
		}

		if (b.begin_game) {
			b.play = true;
			b.mball = true;
			lf = 3;
			b.death = false;
			b.pause = false;

			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 3; j++)
					o.block[j * 6 + i].setPosition(25 + 200 * i, 88 + 88 * (j + 1));
			db = 0;

			for (int i = 6; i < 12; i++)
				if (b.pusklever[1] || b.pusklever[3] ||
					b.pusklever[5] || b.pusklever[7]) {
					o.block[i].setTextureRect(IntRect(140, 0, 140, 26));
					b.rblock[i] = true;
				}
				else {
					o.block[i].setTextureRect(IntRect(0, 0, 140, 26));
					b.rblock[i] = false;
				}

			o.players_platform.setPosition(400, 656);
			o.ball.setPosition(510, 578);
			kx = 1;
			ky = 1;

			if (b.pusklever[2] || b.pusklever[3] ||
				b.pusklever[6] || b.pusklever[7])
				o.pblock.setPosition(0, 481);
			else
				o.pblock.setPosition(1300, 481);

			for (int i = 4; i < 8; i++)
				if (b.pusklever[i]) {
					int pl = rand() % 1030;
					o.platform_killer.setPosition(pl, 88);
				}

			b.begin_game = false;
		}

		if ((b.game_process || (!b.mball && b.play)) && !b.pause)
			o.ball.move(0.65 * kx, 0.65 * ky); // Движение мяча

		Vector2f p = o.players_platform.getPosition();
		Vector2f bl = o.ball.getPosition();

		if ((bl.y < 0 && b.game_process) || (bl.y < 88 && b.play)) //Коллизии мяча и стен
			ky *= -1;
		if (bl.x > 1110 || bl.x < 0)
			kx *= -1;

		//Мяч отбивается игроком
		if (o.ball.getGlobalBounds().intersects(o.players_platform.getGlobalBounds())) {
			ky *= -1;

			o.ball.move(0, -0.5);
		}

		if (b.game_process) {
			if (p.x < bl.x && p.x < 870) {
				o.players_platform.move(0.75, 0); //Движение платформы игроком

				//Подсказки управления
				if (b.show_tips&& b.game_process) {
					if (b.ad)
						o.AD_elements.setTextureRect(IntRect(204, 0, 204, 127));
					else
						o.arrow_elements.setTextureRect(IntRect(204, 0, 204, 127));
				}
			}

			else if (p.x > bl.x) {
				o.players_platform.move(-0.65, 0); //Движение платформы игроком

				//Подсказки управления
				if (b.show_tips&& b.game_process) {
					if (b.ad)
						o.AD_elements.setTextureRect(IntRect(0, 0, 204, 127));
					else
						o.arrow_elements.setTextureRect(IntRect(0, 0, 204, 127));
				}
			}
		}

		if (b.play) {

			if (!b.pause) {
				if (b.ad) {
					if (Keyboard::isKeyPressed(Keyboard::D))
						if (p.x < 870) {
							o.players_platform.move(0.9, 0);

							if (b.mball)
								o.ball.move(0.9, 0);
						}
					if (Keyboard::isKeyPressed(Keyboard::A))
						if (p.x > 0) {
							o.players_platform.move(-0.9, 0);

							if (b.mball)
								o.ball.move(-0.9, 0);
						}
				}
				else {
					if (Keyboard::isKeyPressed(Keyboard::Right))
						if (p.x < 870) {
							o.players_platform.move(0.75, 0);

							if (b.mball)
								o.ball.move(0.75, 0);
						}
					if (Keyboard::isKeyPressed(Keyboard::Left))
						if (p.x > 0) {
							o.players_platform.move(-0.9, 0);

							if (b.mball)
								o.ball.move(-0.9, 0);
						}
				}
			}

			for (int i = 0; i < 18; i++)
				if (o.ball.getGlobalBounds().intersects(o.block[i].getGlobalBounds())) {
					ky *= -1;
					o.ball.move(0, 0.1 * ky);

					if (!b.rblock[i]) {
						o.block[i].setPosition(1300, 0);
						db++;
					}
					else {
						o.block[i].setTextureRect(IntRect(0, 0, 140, 26));

						b.rblock[i] = false;
					}
				}

			if (b.mball && bl.y != 578)
				b.mball = false;

			if (!b.mball && !b.pause) {
				if (b.pusklever[2] || b.pusklever[3] ||
					b.pusklever[6] || b.pusklever[7]) {
					o.pblock.move(0.5 * pbx, 0);

					Vector2f pb = o.pblock.getPosition();
					if (pb.x < 0 || pb.x > 1060)
						pbx *= -1;

					if (o.ball.getGlobalBounds().intersects(o.pblock.getGlobalBounds()))
						ky *= -1;
				}

				for (int i = 4; i < 8; i++)
					if (b.pusklever[i]) {
						o.platform_killer.move(0, 0.3);

						Vector2f pu = o.platform_killer.getPosition();
						if (pu.y > 744) {
							pl = rand() % 1030;
							o.platform_killer.setPosition(pl, 88);
						}

						if (o.ball.getGlobalBounds().intersects(o.platform_killer.getGlobalBounds())) {
							ky *= -1;

							pl = rand() % 1030;
							o.platform_killer.setPosition(pl, 88);
						}

						if (o.players_platform.getGlobalBounds().intersects(o.platform_killer.getGlobalBounds())) {
							b.mball = true;
							lf--;

							o.players_platform.setPosition(400, 656);
							o.ball.setPosition(510, 578);

							pl = rand() % 1030;
							o.platform_killer.setPosition(pl, 88);
						}
					}
			}

			if (bl.y > 700) {
				b.mball = true;
				lf--;

				o.players_platform.setPosition(400, 656);
				o.ball.setPosition(510, 578);
			}

			if (db == 18) {
				b.pob = true;
				b.play = false;

				b.blv[lv + 1] = true;
			}

			if (lf == 0) {
				b.play = false;
				b.death = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
				b.pause = true;
		}

		if (b.blv[1])
			o.level_button[1].setTextureRect(IntRect(160, 160, 160, 160));
		if (b.blv[2])
			o.level_button[2].setTextureRect(IntRect(160 * 2, 160, 160, 160));
		if (b.blv[3])
			o.level_button[3].setTextureRect(IntRect(160 * 3, 160, 160, 160));
		if (b.blv[4])
			o.level_button[4].setTextureRect(IntRect(0, 160 * 2, 160, 160));
		if (b.blv[5])
			o.level_button[5].setTextureRect(IntRect(160, 160 * 2, 160, 160));
		if (b.blv[6])
			o.level_button[6].setTextureRect(IntRect(160 * 2, 160 * 2, 160, 160));
		if (b.blv[7])
			o.level_button[7].setTextureRect(IntRect(160 * 3, 160 * 2, 160, 160));

		// движение элемента выбора управления
		if (!b.ad && px != 583)
			px++;
		else if (b.ad && px != 320)
			px--;
		o.selection_line.setPosition(px, 350);

		if (db == 18 && b.death) {
			b.death = false;
			b.pob = true;
		}

		window.draw(o.background);

		if (b.menu) { // условие того, что открыто меню
			// при данном условии показываются элементы меню
			window.draw(o.gamename); 
			window.draw(o.play_button);
			window.draw(o.settings);
			window.draw(o.exit_button);
		}

		if (b.setting) { //условие того, что открыты настройки
			// при данном условии показываются элементы настроек
			window.draw(o.configure_controls);
			window.draw(o.tips_button);
			window.draw(o.back);
		}

		if (b.show_settings) { // условие того, что открыт раздел управления в настройках
			//при данном условии показываются элементы управления 
			window.draw(o.elems_of_control);
			window.draw(o.selection_line);
			window.draw(o.back);
		}

		if (b.game) { // условие того, что открыто окно с игры
			//при данном условии показаны уровни и кнопка "назад"
			window.draw(o.levels_inscription);
			window.draw(o.back);
			for (int i = 0; i < 8; i++) 
				window.draw(o.level_button[i]);
		}

		if (b.game_process) { // условие того, что игра в процессе
			window.draw(o.players_platform);
			window.draw(o.ball);
			window.draw(o.back);
			window.draw(o.controls_button);
			window.draw(o.begin_button);

			if (b.ad)
				window.draw(o.AD_elements);
			else
				window.draw(o.arrow_elements);
		}

		if (b.play || b.pob || b.death) {
			window.draw(o.line);

			if (!b.pause)
				window.draw(o.pause_button);

			if (!b.death) {
				window.draw(o.players_platform);
				window.draw(o.ball);
			}

			window.draw(o.pblock);

			for (int i = 0; i < lf; i++)
				window.draw(o.life[i]);

			for (int i = 4; i < 8; i++)
				if (b.pusklever[i])
					window.draw(o.platform_killer);

			for (int i = 0; i < 18; i++)
				window.draw(o.block[i]);

			if (b.pob || b.death || b.pause) {
				if (!b.death && b.pob)
					window.draw(o.win);
				else if (b.death && !b.pob)
					window.draw(o.the_end);
				else if (b.pause) {
					window.draw(o.pause_inscription);
					window.draw(o.continue_button);
				}

				window.draw(o.begin_again);

				if (lv < 7 && !b.death && !b.pause)
					window.draw(o.sledur);

				window.draw(o.back_to_menu);
			}
		}

		window.display();
	}

	return 0;
}

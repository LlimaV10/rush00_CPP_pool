/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retroDef.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:22:03 by dbolilyi          #+#    #+#             */
/*   Updated: 2019/04/06 15:22:04 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETRO_DEF_HPP
# define RETRO_DEF_HPP

# include <ctime>

# define COUNT_DIFFERENT_ENEMIES 2

# define MAX_COUNT_PLANETS 4
# define PLANETS_SPAWNNING_REPEAT 300

# define BULLET_CHANGE 3
# define MAX_BULLETS_COUNT 200
# define ENEMIES_SPAWNING_REPEAT 100
# define MIN_SPAWNING_ENEMIES 3
# define MAX_SPAWNING_ENEMIES 8

# define PLAYER_SHOOT_CHANGE 10

// Enemy 1
# define ENEMY1_CHANGE 8
# define MAX_ENEMIES1_COUNT 10
# define ENEMY1_SHOOT_REPEAT 230

// Enemy 2
# define ENEMY2_CHANGE 4
# define MAX_ENEMIES2_COUNT 10
# define ENEMY2_SHOOT_REPEAT 460

// BOSS
# define BOSS_CHANGE 10
//# define MAX_BOSS_COUNT 10
# define BOSS_SHOOT_REPEAT 60
// boss spawning repeat in kills
# define BOSS_SPAWNING_REPEAT 10

# define WINDOW_W 200
# define WINDOW_H 75

// exit states
# define ESCAPE 1
# define FAIL 2
# define WIN 3
# define DELAY (CLOCKS_PER_SEC / 150)

# define EXIT 113
# define SPACE 32
#endif

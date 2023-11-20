/*
==============================================================================

PLACEHOLDER 
A simple test enemy
Eventual Easter egg

==============================================================================
*/

#include "g_local.h"
#include "m_placeholder.h"

static int sound_idle;
static int sound_sight;
static int sound_attack;
static int sound_pain;
static int sound_pain2;
static int sound_death;

void placeholder_idlesound(edict_t* self)
{
	gi.sound(self, CHAN_VOICE, sound_idle, 1, ATTN_IDLE, 0);
}

void placeholder_sight(edict_t* self, edict_t* other)
{
	gi.sound(self, CHAN_VOICE, sound_sight, 1, ATTN_NORM, 0);
}

void placeholder_random_painsound(edict_t* self)
{
	// emit random pain sound
	if (rand() & 1) {
		gi.sound(self, CHAN_VOICE, sound_pain, 1, ATTN_NORM, 0);
	}
	else {
		gi.sound(self, CHAN_VOICE, sound_pain2, 1, ATTN_NORM, 0);
	}
}

qboolean visible(edict_t* self, edict_t* other);

void placeholder_stand(edict_t* self);

mframe_t placeholder_frames_stand[] =
{
	ai_stand, 0, NULL, // 1
	ai_stand, 0, NULL, // 2
	ai_stand, 0, NULL, // 3
	ai_stand, 0, NULL, // 4
	ai_stand, 0, NULL, // 5
	ai_stand, 0, NULL, // 6
	ai_stand, 0, NULL, // 7
	ai_stand, 0, NULL, // 8
	ai_stand, 0, NULL, // 9
	ai_stand, 0, NULL, // 10

	ai_stand, 0, NULL, // 11
	ai_stand, 0, NULL, // 12
	ai_stand, 0, NULL, // 13
	ai_stand, 0, NULL, // 14
	ai_stand, 0, NULL, // 15
	ai_stand, 0, NULL, // 16
	ai_stand, 0, NULL, // 17
	ai_stand, 0, NULL, // 18
	ai_stand, 0, NULL, // 19
	ai_stand, 0, NULL, // 20

	ai_stand, 0, NULL, // 21
	ai_stand, 0, NULL, // 22
	ai_stand, 0, NULL, // 23
	ai_stand, 0, NULL, // 24
	ai_stand, 0, NULL, // 25
	ai_stand, 0, NULL, // 26
	ai_stand, 0, NULL, // 27
	ai_stand, 0, NULL, // 28
	ai_stand, 0, NULL, // 29
	ai_stand, 0, NULL, // 30

	ai_stand, 0, NULL, // 31
	ai_stand, 0, NULL, // 32
	ai_stand, 0, NULL, // 33
	ai_stand, 0, NULL, // 34
	ai_stand, 0, NULL, // 35
	ai_stand, 0, NULL, // 36
	ai_stand, 0, NULL, // 37
	ai_stand, 0, NULL, // 38
	ai_stand, 0, NULL, // 39
	ai_stand, 0, NULL, // 40

	ai_stand, 0, NULL, // 51
	ai_stand, 0, NULL, // 52
	ai_stand, 0, NULL, // 53
	ai_stand, 0, NULL, // 54
	ai_stand, 0, NULL, // 55
	ai_stand, 0, NULL, // 56
	ai_stand, 0, NULL, // 57
	ai_stand, 0, NULL, // 58
	ai_stand, 0, NULL, // 59
	ai_stand, 0, NULL, // 60

	ai_stand, 0, NULL, // 61
	ai_stand, 0, NULL, // 62
	ai_stand, 0, NULL, // 63
	ai_stand, 0, NULL, // 64
	ai_stand, 0, NULL, // 65
	ai_stand, 0, NULL, // 66
	ai_stand, 0, NULL, // 67
	ai_stand, 0, NULL, // 68
	ai_stand, 0, NULL, // 69
	ai_stand, 0, NULL, // 70

	ai_stand, 0, NULL, // 81
	ai_stand, 0, NULL, // 82
	ai_stand, 0, NULL, // 83
	ai_stand, 0, NULL, // 84
	ai_stand, 0, NULL, // 85
	ai_stand, 0, NULL, // 86
	ai_stand, 0, NULL, // 87
	ai_stand, 0, NULL, // 88
	ai_stand, 0, NULL, // 89
	ai_stand, 0, NULL, // 90

	ai_stand, 0, NULL, // 91
	ai_stand, 0, NULL, // 92
	ai_stand, 0, NULL, // 93
	ai_stand, 0, NULL, // 94
	ai_stand, 0, NULL, // 95
	ai_stand, 0, NULL, // 96
	ai_stand, 0, NULL, // 97
	ai_stand, 0, NULL, // 98
	ai_stand, 0, NULL, // 99
	ai_stand, 0, NULL, // 100

	ai_stand, 0, NULL, // 101
	ai_stand, 0, NULL, // 102
	ai_stand, 0, NULL, // 103
	ai_stand, 0, NULL, // 104
	ai_stand, 0, NULL, // 105
	ai_stand, 0, NULL, // 106
	ai_stand, 0, NULL, // 107
	ai_stand, 0, NULL, // 108
	ai_stand, 0, NULL, // 109
	ai_stand, 0, NULL, // 110

	ai_stand, 0, NULL, // 111
	ai_stand, 0, NULL, // 112
	ai_stand, 0, NULL, // 113
	ai_stand, 0, NULL, // 114
	ai_stand, 0, NULL, // 115
	ai_stand, 0, NULL, // 116
	ai_stand, 0, NULL, // 117
	ai_stand, 0, NULL, // 118
	ai_stand, 0, NULL, // 119
	ai_stand, 0, NULL, // 120

	ai_stand, 0, NULL, // 121
	ai_stand, 0, NULL, // 122
	ai_stand, 0, NULL, // 123
	ai_stand, 0, NULL, // 124
	ai_stand, 0, NULL, // 125
	ai_stand, 0, NULL, // 126
	ai_stand, 0, NULL, // 127
	ai_stand, 0, NULL, // 128
	ai_stand, 0, NULL, // 130
	ai_stand, 0, NULL, // 120
};
mmove_t placeholder_move_stand = { FRAME_stand01, FRAME_stand130, placeholder_frames_stand, NULL };

void placeholder_stand(edict_t* self)
{
	self->monsterinfo.currentmove = &placeholder_move_stand;
}

mframe_t placeholder_frames_walk[] =
{
	ai_walk, 0, NULL,
	ai_walk, 3, NULL,
	ai_walk, 4, NULL,
	ai_walk, 5, NULL,
	ai_walk, 6, NULL,
};
mmove_t placeholder_move_walk = { FRAME_stand01, FRAME_stand01, placeholder_frames_walk, NULL };
void placeholder_walk(edict_t* self)
{
	self->monsterinfo.currentmove = &placeholder_frames_walk;
}


mframe_t placeholder_frames_melee[] =
{
	ai_stand, 0, NULL, // 1
	ai_stand, 0, NULL, // 2
	ai_stand, 0, NULL, // 3
	ai_stand, 0, NULL, // 4
	ai_stand, 0, NULL, // 5
	ai_stand, 0, NULL, // 6
	ai_stand, 0, NULL, // 7
	ai_stand, 0, NULL, // 8
	ai_stand, 0, NULL, // 9
	ai_stand, 0, NULL, // 10

	ai_stand, 0, NULL, // 11
	ai_stand, 0, NULL, // 12
	ai_stand, 0, NULL, // 13
	ai_stand, 0, NULL, // 14
	ai_stand, 0, NULL, // 15
	ai_stand, 0, NULL, // 16
	ai_stand, 0, NULL, // 17
	ai_stand, 0, NULL, // 18
	ai_stand, 0, NULL, // 19
	ai_stand, 0, NULL, // 20

	ai_stand, 0, NULL, // 21
	ai_stand, 0, NULL, // 22
	ai_stand, 0, NULL, // 23
	ai_stand, 0, NULL, // 24
	ai_stand, 0, NULL, // 25
	ai_stand, 0, NULL, // 26
	ai_stand, 0, NULL, // 27
	ai_stand, 0, NULL, // 28
	ai_stand, 0, NULL, // 29
	ai_stand, 0, NULL, // 30

	ai_stand, 0, NULL, // 31
};
mmove_t placeholder_move_melee= { FRAME_attak01, FRAME_attak31, placeholder_frames_melee, NULL };
void placeholder_attack(edict_t* self)
{
	if (range(self, self->enemy) == RANGE_MELEE)
	{
		self->monsterinfo.currentmove = &placeholder_move_melee;
	}
}

mframe_t placeholder_frames_pain[] =
{
	ai_move, 2, NULL,
	ai_move, 0, NULL,
	ai_move, -5, NULL,
	ai_move, 3, NULL,
	ai_move, -1, NULL,
	ai_move, 0, NULL,
	ai_move, 0, NULL,
};
mmove_t placeholder_move_pain = { FRAME_attak01, FRAME_attak07, placeholder_frames_pain, NULL };

void placeholder_pain(edict_t* self, edict_t* other, float kick, int damage)
{
	// switch to pain skin
	if(self->health < (self->max_health / 2)) {}

	if (level.time < self->pain_debounce_time)
		return;

	self->pain_debounce_time = level.time + 3;

	placeholder_random_painsound(self);

	if (skill->value == 3)
		return;

	self->monsterinfo.currentmove = &placeholder_move_pain;
		
}

void placeholder_dead(edict_t* self)
{
	VectorSet(self->mins, -16, -16, -24);
	VectorSet(self->maxs, 16, 16, -8);
	self->movetype = MOVETYPE_TOSS;
	self->svflags |= SVF_DEADMONSTER;
	self->nextthink = 0;
	gi.linkentity(self);
}

mframe_t placeholder_frames_death[] =
{
	ai_move, 0,	 NULL,
	ai_move, 0,	 NULL,
	ai_move, 0,	 NULL,
	ai_move, -7, NULL,
	ai_move, -3, NULL,
	ai_move, -5, NULL,
	ai_move, 8,	 NULL,
	ai_move, 6,	 NULL,
	ai_move, 0,	 NULL,
	ai_move, 0,	 NULL,
	ai_move, 0,	 NULL
};
mmove_t placeholder_move_death = { FRAME_attak01, FRAME_attak11, placeholder_frames_death, placeholder_dead };

void placeholder_die(edict_t* self, edict_t* inflictor, edict_t* attacker, int damage, vec3_t point)
{
	int n;

	// gibcheck
	if (self->health <= self->gib_health)
	{
		gi.sound(self, CHAN_VOICE, gi.soundindex("misc/udeath.wav"), 1, ATTN_NORM, 0);
		for (n = 0; n < 2; n++) {
			ThrowGib(self, "models/objects/gibs/bone/tris.md2", damage, GIB_ORGANIC);
		}
		for (n = 0; n < 4; n++) {
			ThrowGib(self, "models/objects/gibs/sm_meat/tris.md2", damage, GIB_ORGANIC);
		}
		ThrowHead(self, "models/objects/gibs/head2/tris.md2", damage, GIB_ORGANIC);
		self->deadflag = DEAD_DEAD;
		return;
	}

	if (self->deadflag == DEAD_DEAD)
		return;

	// normal dying
	gi.sound(self, CHAN_VOICE, sound_death, 1, ATTN_NORM, 0);
	self->deadflag = DEAD_DEAD;
	self->takedamage = DAMAGE_YES;
	self->monsterinfo.currentmove = &placeholder_move_death;
}

void SP_monster_placeholder(edict_t* self)
{
	if (deathmatch->value) {
		G_FreeEdict(self);
		return;
	}

	sound_idle = gi.soundindex("enemies/placeholder/test.wav");
	sound_sight = gi.soundindex("enemies/placeholder/test.wav");
	sound_attack = gi.soundindex("enemies/placeholder/test.wav");
	sound_pain = gi.soundindex("enemies/placeholder/test.wav");
	sound_pain2 = gi.soundindex("enemies/placeholder/test.wav");
	sound_death = gi.soundindex("enemies/placeholder/test.wav");

	self->movetype = MOVETYPE_STEP;
	self->solid = SOLID_BBOX;
	self->s.modelindex = gi.modelindex("models/enemies/placeholder/tris.md2");
	VectorSet(self->mins, -16, -16, -24);
	VectorSet(self->maxs, 16, 16, 32);

	self->health = 50;
	self->gib_health = -50;
	self->mass = 200;

	self->pain = placeholder_pain;
	self->die = placeholder_die;

	self->monsterinfo.stand = placeholder_stand;
	self->monsterinfo.walk = placeholder_walk;
	self->monsterinfo.run = placeholder_walk;
	self->monsterinfo.attack = placeholder_attack;
	self->monsterinfo.melee = placeholder_attack;
	self->monsterinfo.sight = placeholder_sight;
	//self->monsterinfo.search = placeholder_search;

	gi.linkentity(self);

	self->monsterinfo.currentmove = &placeholder_move_stand;
	self->monsterinfo.scale = MODEL_SCALE;

	walkmonster_start(self);
}
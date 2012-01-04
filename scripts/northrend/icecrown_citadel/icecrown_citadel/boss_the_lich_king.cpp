/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * ScriptData
 * SDName: boss_the_lich_king
 * SD%Complete:
 * SDComment:
 * SDCategory: Icecrown Citadel
 */

#include "precompiled.h"
#include "icecrown_citadel.h"

enum BossSpells
{
/*
    SPELL_INFEST                     = 70541,
    SPELL_NECROTIC_PLAGUE            = 70337,
    SPELL_PLAGUE_SIPHON              = 74074,
    SPELL_SOUL_REAPER                = 69409,
    SPELL_SPAWN_DEFILE               = 72762,
    SPELL_HARVEST_SOUL               = 68980,
    SPELL_HARVEST_SOUL_TELEPORT      = 71372,
//
    SPELL_CHANNEL_KING               = 71769,
    SPELL_BROKEN_FROSTMOURNE         = 72398,
    SPELL_BOOM_VISUAL                = 72726,
    SPELL_ICEBLOCK_TRIGGER           = 71614,
    SPELL_TIRION_LIGHT               = 71797,
    SPELL_FROSTMOURNE_TRIGGER        = 72405,
    SPELL_SUMMON_BROKEN_FROSTMOURNE  = 72406,
    SPELL_SUMMON_BROKEN_FROSTMOURNE_2 = 73017,
    SPELL_DISENGAGE                  = 61508,
    SPELL_FURY_OF_FROSTMOURNE        = 70063,
    SPELL_REVIVE_VISUAL              = 37755, //Override?
    SPELL_REVIVE                     = 51918,
    SPELL_CLONE_PLAYER               = 57507,
    SPELL_BERSERK                    = 47008,

//Transition phase
    SPELL_REMORSELESS_WINTER         = 68981,
    SPELL_PAIN_AND_SUFFERING         = 72133,
    SPELL_QUAKE                      = 72262,

//Raging spirit
//    SPELL_SUMMON_RAGING_SPIRIT       = 69201, // triggered
    SPELL_SUMMON_RAGING_SPIRIT       = 69200,
    SPELL_SOUL_SHRIEK                = 69242,

//Ice sphere
    SPELL_SUMMON_ICE_SPHERE          = 69103,
    SPELL_ICE_PULSE                  = 69099,
    SPELL_ICE_BURST                  = 69108,
    SPELL_ICE_SPHERE_VISUAL          = 69090,

//Drudge ghouls
    SPELL_SUMMON_DRUDGE_GHOULS       = 70358,

//Shambling horror
    SPELL_SUMMON_SHAMBLING_HORROR    = 70372,
    SPELL_SHOCKWAVE                  = 72149,
    SPELL_HORROR_ENRAGE              = 72143,

//Vile spirits
    SPELL_SUMMON_VILE_SPIRITS        = 70498,
    SPELL_SPIRITS_BURST              = 70503,

//Valkyr
    SPELL_SUMMON_VALKYR              = 69037,
    NPC_VALKYR                       = 36609,
    SPELL_WINGS_OF_THE_DAMNED        = 74352,

//Defile
    SPELL_DEFILE                     = 72743,

// Menethil
    SPELL_REVALL                     = 26687,
//
    NPC_ICE_SPHERE                   = 36633,
    NPC_DEFILER                      = 38757,
    NPC_RAGING_SPIRIT                = 36701,
    NPC_VILE_SPIRIT                  = 37799,
    NPC_STRANGULATE_VEHICLE          = 36598,
*/
    SPELL_BERSERK               = 47008
};

// talks
enum
{
    SAY_INTRO_1                 = -1631158,
    SAY_INTRO_2                 = -1631159,
    SAY_INTRO_3                 = -1631160,
    SAY_INTRO_4                 = -1631161,
    SAY_INTRO_5                 = -1631162,
    SAY_AGGRO                   = -1631163,
    SAY_REMORSELESS_WINTER      = -1631164,
    SAY_SHATTER_ARENA           = -1631165,
    SAY_SUMMON_VALKYR           = -1631166,
    SAY_HARVEST_SOUL            = -1631167,
    SAY_FM_TERENAS_AID_1        = -1631168,
    SAY_FM_TERENAS_AID_2        = -1631169,
    SAY_FM_TERENAS_AID_3        = -1631170,
    SAY_FM_PLAYER_ESCAPE        = -1631171,
    SAY_FM_PLAYER_DEATH         = -1631172,
    SAY_SPECIAL_1               = -1631173,
    SAY_SPECIAL_2               = -1631174,
    SAY_LAST_PHASE              = -1631175,
    SAY_SLAY_1                  = -1631176,
    SAY_SLAY_2                  = -1631177,
    SAY_ENRAGE                  = -1631178,
    SAY_OUTRO_1                 = -1631179,
    SAY_OUTRO_2                 = -1631180,
    SAY_OUTRO_3                 = -1631181,
    SAY_OUTRO_4                 = -1631182,
    SAY_OUTRO_5                 = -1631183,
    SAY_OUTRO_6                 = -1631184,
    SAY_OUTRO_7                 = -1631185,
    SAY_OUTRO_8                 = -1631186,
    SAY_OUTRO_9                 = -1631187,
    SAY_OUTRO_10                = -1631188,
    SAY_OUTRO_11                = -1631189,
    SAY_OUTRO_12                = -1631190,
    SAY_OUTRO_13                = -1631191,
    SAY_OUTRO_14                = -1631192,
};

enum Common
{
     FINAL_ARTHAS_MOVIE         = 16,
};

enum Phase
{
    PHASE_INTRO                 = 0,    // intro
    PHASE_ONE                   = 1,    // phase one
    PHASE_RUNNING_WINTER_ONE    = 2,    // running to center of platform to cast Remorseless Winter
    PHASE_TRANSITION_ONE        = 3,    // Remorseless Winter aura and casting spells, summoning orbs and spirits
    PHASE_QUAKE_ONE             = 4,    // casting Quake
    PHASE_TWO                   = 5,    // phase two with val'kyrs and some more spells
    PHASE_RUNNING_WINTER_TWO    = 6,    // running to center of platform to cast Remorseless Winter again
    PHASE_TRANSITION_TWO        = 7,    // second Remorseless Winter phase
    PHASE_QUAKE_TWO             = 8,    // second Quake casting
    PHASE_THREE                 = 9,    // phase three, casting Soul Harvest (Frostmourne phase)
    PHASE_CUTSCENE              = 10,   // phase when LK kills raid, Terenas comes etc.
    PHASE_DEATH_AWAITS          = 11,   // strangulating Lich King, raid group finishing him
};

enum Point
{
    POINT_CENTER_LAND           = 1
};

static Locations SpawnLoc[] =
{
    {459.93689f, -2124.638184f, 1040.860107f},    // 0 Lich King Intro
    {503.15652f, -2124.516602f, 1040.860107f},    // 1 Center of the platform
    {491.27118f, -2124.638184f, 1040.860107f},    // 2 Tirion 1
    {481.69797f, -2124.638184f, 1040.860107f},    // 3 Tirion 2
    {498.00448f, -2201.573486f, 1046.093872f},    // 4 Valkyrs?
    {517.48291f, -2124.905762f, 1040.861328f},    // 5 Tirion?
    {529.85302f, -2124.709961f, 1040.859985f},    // 6 Lich king final, o=3.1146
    {520.311f, -2124.709961f, 1040.859985f},      // 7 Frostmourne
};

/**
 * The Lich King
 */
struct MANGOS_DLL_DECL boss_the_lich_king_iccAI : public base_icc_bossAI
{
    boss_the_lich_king_iccAI(Creature* pCreature) : base_icc_bossAI(pCreature){}

    uint32 m_uiPhase;
    uint32 m_uiPhaseTimer;
    uint32 m_uiBerserkTimer;
    uint32 m_uiGhoulsTimer;
    uint32 m_uiHorrorTimer;
    uint32 m_uiNecroticPlagueTimer;
    uint32 m_uiInfestTimer;
    uint32 m_uiShadowTrapTimer;
    uint32 m_uiPainSufferingTimer;
    uint32 m_uiRagingSpiritTimer;
    uint32 m_uiIceSphereTimer;
    uint32 m_uiValkyrTimer;
    uint32 m_uiDefileTimer;
    uint32 m_uiSoulReaperTimer;
    uint32 m_uiHarvestSoulTimer;
    uint32 m_uiVileSpiritsTimer;

    void Reset()
    {
        m_uiPhase               = PHASE_INTRO;
        m_uiBerserkTimer        = 15 * MINUTE * IN_MILLISECONDS;
        m_uiPhaseTimer          = 60000; // first transition phase duration
        m_uiGhoulsTimer         = 13000;
        m_uiHorrorTimer         = 21000;
        m_uiInfestTimer         = 20000;
        m_uiNecroticPlagueTimer = 23000;
        m_uiShadowTrapTimer     = 15000;
        m_uiPainSufferingTimer  = 2000;
        m_uiRagingSpiritTimer   = 20000;
        m_uiIceSphereTimer      = 6000;
        m_uiValkyrTimer         = 10000;
        m_uiDefileTimer         = 30000;
        m_uiSoulReaperTimer     = 25000;
        m_uiHarvestSoulTimer    = 5000;
        m_uiVileSpiritsTimer    = 20000;
    }

    void Aggro(Unit *pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        m_uiPhase = PHASE_ONE;

        if (m_pInstance)
            m_pInstance->SetData(TYPE_LICH_KING, IN_PROGRESS);
    }

    void KilledUnit(Unit *pWho)
    {
        if (pWho->GetTypeId() == TYPEID_PLAYER)
            DoScriptText(SAY_SLAY_1 - urand(0, 1), m_creature);
    }

    void JustDied(Unit *pKiller)
    {
        // play cinematic
        if (m_pInstance)
            m_pInstance->SetData(TYPE_LICH_KING, DONE);
    }

    void JustReachedHome()
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_LICH_KING, FAIL);
    }

    void MovementInform(uint32 uiMovementType, uint32 uiData)
    {
        if (uiMovementType != POINT_MOTION_TYPE)
            return;

        switch(uiData)
        {
            case POINT_CENTER_LAND:
            {
                // Remorseless Winter
                DoScriptText(SAY_REMORSELESS_WINTER, m_creature);
                // DoCastSpellIfCan(m_creature, SPELL_REMORSELESS_WINTER);
                if (m_uiPhase == PHASE_RUNNING_WINTER_ONE)
                    m_uiPhase = PHASE_TRANSITION_ONE;
                else if (m_uiPhase == PHASE_RUNNING_WINTER_TWO)
                    m_uiPhase = PHASE_TRANSITION_TWO;

                break;
            }
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (m_uiPhase != PHASE_INTRO)
        {
            // check evade
            if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
                return;

            // Berserk
            if (m_uiBerserkTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_BERSERK) == CAST_OK)
                {
                    DoScriptText(SAY_ENRAGE, m_creature);
                    m_uiBerserkTimer = 30 * MINUTE * IN_MILLISECONDS;
                }
            }
            else
                m_uiBerserkTimer -= uiDiff;
        }

        switch(m_uiPhase)
        {
            case PHASE_INTRO:
            {
                // wait until set in combat
                return;
            }
            case PHASE_ONE:
            {
                // check HP
                if (m_creature->GetHealthPercent() <= 70.0f)
                {
                    // phase transition
                    SetCombatMovement(false);
                    m_creature->GetMotionMaster()->Clear();
                    m_creature->GetMotionMaster()->MovePoint(POINT_CENTER_LAND, SpawnLoc[1].x, SpawnLoc[1].y, SpawnLoc[1].z);
                    m_uiPhaseTimer = 60000;
                    m_uiPhase = PHASE_RUNNING_WINTER_ONE;
                }

                // Necrotic Plague
                if (m_uiNecroticPlagueTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_NECROTIC_PLAGUE) == CAST_OK)
                        m_uiNecroticPlagueTimer = 15000;
                }
                else
                    m_uiNecroticPlagueTimer -= uiDiff;

                // Infest
                if (m_uiInfestTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_INFEST) == CAST_OK)
                        m_uiInfestTimer = urand(20000, 25000);
                }
                else
                    m_uiInfestTimer -= uiDiff;

                // Summon Ghouls
                if (m_uiGhoulsTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_GHOULS) == CAST_OK)
                    m_uiGhoulsTimer = 20000;
                }
                else
                    m_uiGhoulsTimer -= uiDiff;

                // Summon Shambling Horror
                if (m_uiHorrorTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_HORROR) == CAST_OK)
                        m_uiHorrorTimer = 60000;
                }
                else
                    m_uiHorrorTimer -= uiDiff;

                // Shadow Trap (heroic)
                if (m_bIsHeroic)
                {
                    if (m_uiShadowTrapTimer < uiDiff)
                    {
                        // if (DoCastSpellIfCan(m_creature, SPELL_SHADOW_TRAP) == CAST_OK)
                            m_uiShadowTrapTimer = 15000;
                    }
                    else
                        m_uiShadowTrapTimer -= uiDiff;
                }

                DoMeleeAttackIfReady();
                break;
            }
            case PHASE_RUNNING_WINTER_ONE:
            case PHASE_RUNNING_WINTER_TWO:
            {
                // wait for waypoint arrival
                break;
            }
            case PHASE_TRANSITION_ONE:
            case PHASE_TRANSITION_TWO:
            {
                if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
                    return;

                // remorseless winter, casting some stuff, summoning some creatures
                // phase end timer
                if (m_uiPhaseTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_QUAKE) == CAST_OK)
                    {
                        DoScriptText(SAY_SHATTER_ARENA, m_creature);
                        m_uiPhase = (m_uiPhase == PHASE_TRANSITION_ONE ? PHASE_QUAKE_ONE : PHASE_QUAKE_TWO);
                        m_uiPhaseTimer = 3000;
                    }
                }
                else
                    m_uiPhaseTimer -= uiDiff;

                // Pain and Suffering
                if (m_uiPainSufferingTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_PAIN_AND_SUFFERING) == CAST_OK)
                        m_uiPainSufferingTimer = urand(1000, 3000);
                }
                else
                    m_uiPainSufferingTimer -= uiDiff;

                // Summon Ice Sphere
                if (m_uiIceSphereTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_ICE_SPHERE) == CAST_OK)
                        m_uiIceSphereTimer = 6000;
                }
                else
                    m_uiIceSphereTimer -= uiDiff;

                // Summon Raging Spirit
                if (m_uiRagingSpiritTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_RAGING_SPIRIT) == CAST_OK)
                        m_uiRagingSpiritTimer = (m_uiPhase == PHASE_TRANSITION_ONE ? 20000 : 15000);
                }
                else
                    m_uiRagingSpiritTimer -= uiDiff;

                break;
            }
            case PHASE_QUAKE_ONE:
            case PHASE_QUAKE_TWO:
            {
                // Casting Quake spell - phase end timer
                if (m_uiPhaseTimer < uiDiff)
                {
                    m_uiPhase = (m_uiPhase == PHASE_QUAKE_ONE ? PHASE_TWO : PHASE_THREE);
                    SetCombatMovement(true);
                    m_creature->GetMotionMaster()->Clear();
                    m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                    return;
                }
                else
                    m_uiPhaseTimer -= uiDiff;

                break;
            }
            case PHASE_TWO:
            {
                // check HP
                if (m_creature->GetHealthPercent() <= 40.0f)
                {
                    // phase transition
                    SetCombatMovement(false);
                    m_creature->GetMotionMaster()->Clear();
                    m_creature->GetMotionMaster()->MovePoint(POINT_CENTER_LAND, SpawnLoc[1].x, SpawnLoc[1].y, SpawnLoc[1].z);
                    m_uiPhaseTimer = 60000;
                    m_uiPhase = PHASE_RUNNING_WINTER_TWO;
                }

                // Soul Reaper
                if (m_uiSoulReaperTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature->getVictim, SPELL_SOUL_REAPER) == CAST_OK)
                        m_uiSoulReaperTimer = 30000;
                }
                else
                    m_uiSoulReaperTimer -= uiDiff;

                // Infest
                if (m_uiInfestTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_INFEST) == CAST_OK)
                        m_uiInfestTimer = urand(20000, 25000);
                }
                else
                    m_uiInfestTimer -= uiDiff;

                // Defile
                if (m_uiDefileTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_DEFILE) == CAST_OK)
                        m_uiDefileTimer = 30000;
                }
                else
                    m_uiDefileTimer -= uiDiff;

                // Summon Val'kyr
                if (m_uiValkyrTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_VALKYR) == CAST_OK)
                        m_uiValkyrTimer = 50000;
                }
                else
                    m_uiValkyrTimer -= uiDiff;

                DoMeleeAttackIfReady();
                break;
            }
            case PHASE_THREE:
            {
                // Soul Reaper
                if (m_uiSoulReaperTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature->getVictim, SPELL_SOUL_REAPER) == CAST_OK)
                        m_uiSoulReaperTimer = 30000;
                }
                else
                    m_uiSoulReaperTimer -= uiDiff;

                // Defile
                if (m_uiDefileTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_DEFILE) == CAST_OK)
                        m_uiDefileTimer = 30000;
                }
                else
                    m_uiDefileTimer -= uiDiff;

                // Harvest Soul
                if (m_uiHarvestSoulTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_HARVEST_SOUL) == CAST_OK)
                        m_uiHarvestSoulTimer = urand(60000, 70000);
                }
                else
                    m_uiHarvestSoulTimer -= uiDiff;

                // Vile Spirits (start moving after 15seconds)
                if (m_uiVileSpiritsTimer < uiDiff)
                {
                    // if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_VILE_SPIRITS) == CAST_OK)
                        m_uiVileSpiritsTimer = 30000;
                }
                else
                    m_uiVileSpiritsTimer -= uiDiff;

                DoMeleeAttackIfReady();
                break;
            }
        }
    }
};

CreatureAI* GetAI_boss_the_lich_king_icc(Creature* pCreature)
{
    return new boss_the_lich_king_iccAI(pCreature);
}

/*
struct MANGOS_DLL_DECL boss_the_lich_king_iccAI : public BSWScriptedAI
{
    boss_the_lich_king_iccAI(Creature* pCreature) : BSWScriptedAI(pCreature)
    {
        pInstance = (instance_icecrown_spire*)pCreature->GetInstanceData();
        oldflag = 0;
        Reset();
    }

    instance_icecrown_spire* pInstance;
    uint8 stage;
    uint32 nextEvent;
    uint32 nextPoint;
    uint32 UpdateTimer;
    uint32 oldflag;
    bool movementstarted;
    bool battlestarted;
    bool finalphase;
    Creature* pTirion;
    Creature* pFrostmourne;
    std::list<ObjectGuid> mobsGUIDList;

    void Reset()
    {
        if(!pInstance) return;
        resetTimers();
        mobsGUIDList.clear();
        stage = 0;
        nextEvent = 0;
        nextPoint = 0;
        movementstarted = false;
        battlestarted = false;
        finalphase = false;
        m_creature->SetOrientation(0.0f);
        pInstance->DoCloseDoor(pInstance->GetData64(GO_ICESHARD_1));
        pInstance->DoCloseDoor(pInstance->GetData64(GO_ICESHARD_2));
        pInstance->DoCloseDoor(pInstance->GetData64(GO_ICESHARD_3));
        pInstance->DoCloseDoor(pInstance->GetData64(GO_ICESHARD_4));
        if (oldflag)
            if (GameObject* pGoFloor = pInstance->GetSingleGameObjectFromStorage(GO_ARTHAS_PLATFORM))
            {
               pGoFloor->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED | GO_FLAG_NODESPAWN);
               pGoFloor->SetUInt32Value(GAMEOBJECT_BYTES_1,oldflag);
            }
        pInstance->DoCloseDoor(pInstance->GetData64(GO_FROSTY_WIND));
    }

    void MoveInLineOfSight(Unit* pWho)
    {
    }

    void EnterEvadeMode()
    {
        if (!pInstance) return;
        if (finalphase && pInstance->GetData(TYPE_LICH_KING) == IN_PROGRESS) return;

        DespawnMobs();
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreatureAddon();
        if (m_creature->isAlive())
            m_creature->GetMotionMaster()->MoveTargetedHome();

        m_creature->SetLootRecipient(NULL);

        Reset();
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE || !movementstarted) return;
        if (id == nextPoint)
        {
            movementstarted = false;
            pInstance->SetData(TYPE_EVENT,nextEvent);
            m_creature->GetMotionMaster()->MovementExpired();
        }
    }

    void KilledUnit(Unit* pVictim)
    {

        if (!battlestarted)
            return;

        DoScriptText(SAY_SLAY_1 - urand(0, 1),m_creature,pVictim);
    }

    void JustReachedHome()
    {
        if (!pInstance) return;
        pInstance->SetData(TYPE_LICH_KING, FAIL);
        stage = 0;
        battlestarted = false;
        finalphase = false;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }


    void StartMovement(uint32 id, uint32 _nextEvent)
    {
        nextPoint = id;
        nextEvent = _nextEvent;
        m_creature->GetMotionMaster()->Clear();
        m_creature->GetMotionMaster()->MovePoint(id, SpawnLoc[id].x, SpawnLoc[id].y, SpawnLoc[id].z);
        pInstance->SetData(TYPE_EVENT,0);
        movementstarted = true;
    }

    void JustSummoned(Creature* summoned)
    {
        if(!pInstance || !summoned) return;

        if (Unit* pTarget = doSelectRandomPlayerAtRange(60.0f))
           {
              summoned->SetInCombatWith(pTarget);
              summoned->AddThreat(pTarget,100.0f);
           }
        mobsGUIDList.push_back(summoned->GetObjectGuid());
    }

    void DespawnMobs()
    {
        if (mobsGUIDList.empty())
            return;

        for(std::list<ObjectGuid>::iterator itr = mobsGUIDList.begin(); itr != mobsGUIDList.end(); ++itr)
        {
            if (Creature* pTemp = m_creature->GetMap()->GetCreature(*itr))
                if (pTemp->isAlive())
                {
                    pTemp->DeleteThreatList();
                    pTemp->CombatStop(true);
                    pTemp->DealDamage(pTemp, pTemp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                }
        }
        mobsGUIDList.clear();
    }


    void Aggro(Unit* pWho)
    {
        if (!pInstance)  
            return;

        pInstance->SetData(TYPE_LICH_KING, IN_PROGRESS);
    }

    void JustDied(Unit *killer)
    {
        if(!pInstance)
            return;

        DoScriptText(SAY_OUTRO_14, m_creature);
        pInstance->SetData(TYPE_LICH_KING, DONE);

        pInstance->SetData(TYPE_EVENT,14010);
        DespawnMobs();

    }

    void UpdateAI(const uint32 diff)
    {

        if(!pInstance) return;

        if (pInstance->GetData(TYPE_EVENT_NPC) == NPC_LICH_KING)
        {
            UpdateTimer = pInstance->GetData(TYPE_EVENT_TIMER);
            if (UpdateTimer <= diff)
            {
            debug_log("EventMGR: creature %u received signal %u ",m_creature->GetEntry(),pInstance->GetData(TYPE_EVENT));
            switch (pInstance->GetData(TYPE_EVENT))
                {
                case 12000:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                          m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                          StartMovement(0,12020);
                          break;
                case 12020:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                          DoScriptText(SAY_INTRO_1, m_creature);
                          UpdateTimer = 12000;
                          pInstance->SetData(TYPE_EVENT,12030);
                          break;
                case 12040:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                          DoScriptText(SAY_INTRO_3, m_creature);
                          UpdateTimer = 8000;
                          pInstance->SetData(TYPE_EVENT,12041);
                          break;
                case 12041:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_LAUGH);
                          UpdateTimer = 3000;
                          pInstance->SetData(TYPE_EVENT,12042);
                          break;
                case 12042:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,EMOTE_ONESHOT_POINT_NOSHEATHE);
                          UpdateTimer = 2000;
                          pInstance->SetData(TYPE_EVENT,12043);
                          break;
                case 12043:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,EMOTE_ONESHOT_NONE);
                          UpdateTimer = 10000;
                          pInstance->SetData(TYPE_EVENT,12050);
                          break;
                case 12060:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                          DoScriptText(SAY_INTRO_5, m_creature);
                          UpdateTimer = 10000;
                          pInstance->SetData(TYPE_EVENT,12080);
                          break;
                case 12080:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,EMOTE_STATE_READY2H);
                          UpdateTimer = 2000;
                          pInstance->SetData(TYPE_EVENT,12100);
                          break;
                case 12100:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,EMOTE_ONESHOT_NONE);
                          UpdateTimer = 6000;
                          pInstance->SetData(TYPE_EVENT,12120);
                          break;
                case 12120:
                          m_creature->GetMotionMaster()->Clear();
                          m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                          SetCombatMovement(true);
                          m_creature->SetInCombatWithZone();
                          battlestarted = true;
                          pInstance->SetData(TYPE_EVENT,12200);
                          UpdateTimer = 10000;
                          break;
                case 12200:
                          DoScriptText(SAY_AGGRO, m_creature);
                          UpdateTimer = 5000;
                          pInstance->SetData(TYPE_EVENT,12220);
                          break;
                case 13000:
                          m_creature->SetOrientation(3.1146f);
                          DoScriptText(SAY_OUTRO_1, m_creature);
                          UpdateTimer = 12000;
                          finalphase = true;
                          doCast(SPELL_FURY_OF_FROSTMOURNE);
                          pInstance->SetData(TYPE_EVENT,13020);
                          if (pTirion = pInstance->GetSingleCreatureFromStorage(NPC_TIRION))
                          {
                              m_creature->SetInCombatWith(pTirion);
                              pTirion->AddThreat(m_creature, 1000.0f);
                          }
                          m_creature->SetInCombatWithZone();
                          break;
                case 13020:
                          DoScriptText(SAY_OUTRO_2, m_creature);
                          UpdateTimer = 12000;
                          pInstance->SetData(TYPE_EVENT,13060);
                          break;
                case 13060:
                          DoScriptText(SAY_OUTRO_3, m_creature);
                          UpdateTimer = 15000;
                          pInstance->SetData(TYPE_EVENT,13100);
                          break;
                case 13100:
                          DoScriptText(SAY_OUTRO_4, m_creature);
                          UpdateTimer = 15000;
                          pInstance->SetData(TYPE_EVENT,13110);
                          doCast(SPELL_CHANNEL_KING);
                          break;
                case 13120:
                          DoScriptText(SAY_OUTRO_5, m_creature);
                          UpdateTimer = 12000;
                          pInstance->SetData(TYPE_EVENT,13130);
                          break;
                case 13140:
                          UpdateTimer = 6000;
                          doRemove(SPELL_CHANNEL_KING);
                          pInstance->SetData(TYPE_EVENT,13150);
                          m_creature->CastSpell(m_creature, SPELL_SUMMON_BROKEN_FROSTMOURNE, false);
                          break;
                case 13160:
                          UpdateTimer = 6000;
                          pInstance->SetData(TYPE_EVENT,13170);
                          m_creature->CastSpell(m_creature, SPELL_SUMMON_BROKEN_FROSTMOURNE_2, false);
                          break;
                case 13180:
                          UpdateTimer = 12000;
                          pInstance->SetData(TYPE_EVENT,13190);
                          if (pFrostmourne = m_creature->SummonCreature(NPC_FROSTMOURNE_HOLDER, SpawnLoc[7].x, SpawnLoc[7].y, SpawnLoc[7].z, 0, TEMPSUMMON_MANUAL_DESPAWN, 5000))
                             {
                                 pFrostmourne->CastSpell(pFrostmourne, SPELL_BROKEN_FROSTMOURNE, false);
                                 pFrostmourne->CastSpell(pFrostmourne, SPELL_FROSTMOURNE_TRIGGER, false);
                                 pFrostmourne->GetMotionMaster()->MoveChase(m_creature);
                                 m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED);
                             }
                          break;
                case 13200:
                          DoScriptText(SAY_OUTRO_7, m_creature);
                          m_creature->RemoveAurasDueToSpell(SPELL_SUMMON_BROKEN_FROSTMOURNE);
                          m_creature->RemoveAllAuras();
                          pFrostmourne->RemoveAurasDueToSpell(SPELL_FROSTMOURNE_TRIGGER);
                          UpdateTimer = 5000;
                          pInstance->SetData(TYPE_EVENT,13210);
                          break;
                case 13280:
                          UpdateTimer = 2000;
                          pInstance->SetData(TYPE_EVENT,13290);
                          stage = 13;
                          if (pFrostmourne) pFrostmourne->ForcedDespawn();
                          if (Creature* pTemp = pInstance->GetSingleCreatureFromStorage(NPC_FROSTMOURNE_TRIGGER))
                             pTemp->ForcedDespawn();
                          if (Creature* pTemp = pInstance->GetSingleCreatureFromStorage(NPC_FROSTMOURNE_HOLDER))
                             pTemp->ForcedDespawn();
                          SetCombatMovement(true);
                          battlestarted = true;
                          break;
                default:
                          break;
                }
             } else UpdateTimer -= diff;
             pInstance->SetData(TYPE_EVENT_TIMER, UpdateTimer);
        }

        if (battlestarted && !m_creature->SelectHostileTarget() && !finalphase)
        {
            battlestarted = false;
            pInstance->SetData(TYPE_LICH_KING, FAIL);
            pInstance->SetData(TYPE_EVENT,0);
            EnterEvadeMode();
            return;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        switch(stage)
        {
            case 0:           // Phase 1
//                    timedCast(SPELL_SHOCKWAVE, diff);
                    timedCast(SPELL_INFEST, diff);
                    timedCast(SPELL_SUMMON_DRUDGE_GHOULS, diff);
                    timedCast(SPELL_PLAGUE_SIPHON, diff);
                    timedCast(SPELL_SUMMON_SHAMBLING_HORROR, diff);
                    timedCast(SPELL_NECROTIC_PLAGUE, diff);

                    DoMeleeAttackIfReady();
                    if (timedQuery(SPELL_BERSERK, diff))
                    {
                        doCast(SPELL_BERSERK);
                        DoScriptText(SAY_SLAY_2,m_creature);
                    };

                    if (m_creature->GetHealthPercent() < 70.0f)
                       {
                            stage = 1;
                       }
                    break;
            case 1:             // Go in transition phase
                    m_creature->AttackStop();
                    m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    SetCombatMovement(false);
                    StartMovement(1,0);
                    stage = 2;
                    break;
            case 2:
                    if (movementstarted) return;
                    doCast(SPELL_REMORSELESS_WINTER);
                    stage = 3;
                    break;
            case 3:
                    timedCast(SPELL_SUMMON_RAGING_SPIRIT, diff);
                    timedCast(SPELL_SUMMON_ICE_SPHERE, diff);
                    timedCast(SPELL_PAIN_AND_SUFFERING, diff);

                    if (timedQuery(SPELL_BERSERK, diff))
                    {
                        doCast(SPELL_BERSERK);
                        DoScriptText(SAY_SLAY_2,m_creature);
                    };

                    if (timedQuery(SPELL_REMORSELESS_WINTER, diff))
                       {
                            doCast(SPELL_QUAKE);
                            stage = 4;
                            DoScriptText(SAY_SHATTER_ARENA, m_creature);
                            pInstance->DoOpenDoor(pInstance->GetData64(GO_SNOW_EDGE));
                       };
                    break;
            case 4:           // Platform destruct
                    if (timedQuery(SPELL_QUAKE, diff))
                       {
                            pInstance->DoOpenDoor(pInstance->GetData64(GO_ICESHARD_1));
                            pInstance->DoOpenDoor(pInstance->GetData64(GO_ICESHARD_2));
                            pInstance->DoOpenDoor(pInstance->GetData64(GO_ICESHARD_3));
                            pInstance->DoOpenDoor(pInstance->GetData64(GO_ICESHARD_4));
                            if (GameObject* pGoFloor = pInstance->GetSingleGameObjectFromStorage(GO_ARTHAS_PLATFORM))
                            {
                                 pGoFloor->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED | GO_FLAG_NODESPAWN);
                                 oldflag = pGoFloor->GetUInt32Value(GAMEOBJECT_BYTES_1);
                                 pGoFloor->SetUInt32Value(GAMEOBJECT_BYTES_1,8449);
                            }
                            pInstance->DoCloseDoor(pInstance->GetData64(GO_FROSTY_WIND));
                            pInstance->DoCloseDoor(pInstance->GetData64(GO_SNOW_EDGE));
                            m_creature->GetMotionMaster()->Clear();
                            m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            SetCombatMovement(true);
                            stage = 5;
                       }
                    break;
            case 5:           // Phase 2

                    if (timedQuery(SPELL_SPAWN_DEFILE, diff))
                       {
                            doCast(SPELL_SPAWN_DEFILE);
                       }
                    if (timedQuery(SPELL_SUMMON_VALKYR, diff))
                       {
                            doCast(SPELL_SUMMON_VALKYR);
                            DoScriptText(SAY_SUMMON_VALKYR,m_creature);
                       }

                    timedCast(SPELL_SOUL_REAPER, diff);
                    timedCast(SPELL_INFEST, diff);

                    DoMeleeAttackIfReady();

                    if (timedQuery(SPELL_BERSERK, diff))
                    {
                        doCast(SPELL_BERSERK);
                        DoScriptText(SAY_SLAY_2,m_creature);
                    };

                    if (m_creature->GetHealthPercent() < 40.0f)
                       {
                            stage = 6;
                            DoScriptText(SAY_REMORSELESS_WINTER,m_creature);
                       }
                    break;
            case 6:           // Go in transition phase
                    m_creature->AttackStop();
                    m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    SetCombatMovement(false);
                    StartMovement(1,0);
                    stage = 7;
                    break;
            case 7:          // Platform restore
                    if (movementstarted) return;
                    if (GameObject* pGoFloor = pInstance->GetSingleGameObjectFromStorage(GO_ARTHAS_PLATFORM))
                    {
                        pGoFloor->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED | GO_FLAG_NODESPAWN);
                        pGoFloor->SetUInt32Value(GAMEOBJECT_BYTES_1,oldflag);
                    }
                    pInstance->DoOpenDoor(pInstance->GetData64(GO_FROSTY_WIND));
                    doCast(SPELL_REMORSELESS_WINTER);
                    stage = 8;
                    break;
            case 8:
                    timedCast(SPELL_SUMMON_RAGING_SPIRIT, diff);
                    timedCast(SPELL_SUMMON_ICE_SPHERE, diff);
                    timedCast(SPELL_PAIN_AND_SUFFERING, diff);

                    if (timedQuery(SPELL_BERSERK, diff))
                    {
                        doCast(SPELL_BERSERK);
                        DoScriptText(SAY_SLAY_2,m_creature);
                    };

                    if (timedQuery(SPELL_REMORSELESS_WINTER, diff))
                       {
                            DoScriptText(SAY_SHATTER_ARENA, m_creature);
                            doCast(SPELL_SUMMON_VILE_SPIRITS);
                            for (uint8 i = 0; i < getSpellData(SPELL_SUMMON_VILE_SPIRITS); ++i)
                                 doCast(NPC_VILE_SPIRIT);
                            doCast(SPELL_QUAKE);
                            stage = 9;
                            pInstance->DoOpenDoor(pInstance->GetData64(GO_SNOW_EDGE));
                       };

                    break;
            case 9:           // Platform destruct
                    if (timedQuery(SPELL_QUAKE, diff))
                       {
                            if (GameObject* pGoFloor = pInstance->GetSingleGameObjectFromStorage(GO_ARTHAS_PLATFORM))
                            {
                                 pGoFloor->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED | GO_FLAG_NODESPAWN);
                                 oldflag = pGoFloor->GetUInt32Value(GAMEOBJECT_BYTES_1);
                                 pGoFloor->SetUInt32Value(GAMEOBJECT_BYTES_1,8449);
                            }
                            pInstance->DoCloseDoor(pInstance->GetData64(GO_SNOW_EDGE));
                            pInstance->DoCloseDoor(pInstance->GetData64(GO_FROSTY_WIND));
                            m_creature->GetMotionMaster()->Clear();
                            m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            SetCombatMovement(true);
                            stage = 10;
                       }
                   break;
            case 10:           // Phase 3
                    if (timedQuery(SPELL_SPAWN_DEFILE, diff))
                       {
                            doCast(SPELL_SPAWN_DEFILE);
                       }
                    timedCast(SPELL_SOUL_REAPER, diff);

                    if (timedQuery(SPELL_HARVEST_SOUL, diff))
                       {
                            doCast(SPELL_HARVEST_SOUL);
                            DoScriptText(SAY_HARVEST_SOUL,m_creature);
                       }

                    timedCast(SPELL_SOUL_REAPER, diff);
                    timedCast(SPELL_INFEST, diff);

                    DoMeleeAttackIfReady();

                    if (m_creature->GetHealthPercent() < 10.0f)
                       {
                            stage = 11;
                            DoScriptText(SAY_LAST_PHASE,m_creature);
                       }
                    break;
            case 11:           // Ending Phase start
                    m_creature->AttackStop();
                    SetCombatMovement(false);
                    StartMovement(6,13000);
                    stage = 12;
                    battlestarted = false;
                    break;
            case 12:
                    break;
            case 13:
                    DoMeleeAttackIfReady();
                    break;
        }
    }
};
*/
/*
struct MANGOS_DLL_DECL boss_tirion_iccAI : public ScriptedAI
{
    boss_tirion_iccAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance *pInstance;
    uint32 UpdateTimer;
    uint32 nextEvent;
    uint32 nextPoint;
    bool movementstarted;
    ObjectGuid MenethilGUID;

    void EnterEvadeMode()
    {
        if (!pInstance) return;
        if (pInstance->GetData(TYPE_LICH_KING) == IN_PROGRESS) return;
        ScriptedAI::EnterEvadeMode();
    }

    void Reset()
    {
        if(!pInstance) return;
        movementstarted = false;
        m_creature->RemoveAurasDueToSpell(SPELL_ICEBLOCK_TRIGGER);
        m_creature->SetOrientation(M_PI_F);
    }

    void StartMovement(uint32 id, uint32 _nextEvent)
    {
        nextPoint = id;
        nextEvent = _nextEvent;
        m_creature->GetMotionMaster()->MovePoint(id, SpawnLoc[id].x, SpawnLoc[id].y, SpawnLoc[id].z);
        pInstance->SetData(TYPE_EVENT,0);
        movementstarted = true;
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE || !movementstarted) return;
        if (id == nextPoint)
        {
            movementstarted = false;
            pInstance->SetData(TYPE_EVENT,nextEvent);
            m_creature->GetMotionMaster()->MovementExpired();
        }
    }

    void doSendCinematic()
    {
        Map::PlayerList const &pList = m_creature->GetMap()->GetPlayers();
        if (pList.isEmpty()) return;
        for (Map::PlayerList::const_iterator i = pList.begin(); i != pList.end(); ++i)
             if (Player* pPlayer = i->getSource())
                 if (pPlayer && pPlayer->isAlive() && pPlayer->IsInMap(m_creature))
                     pPlayer->SendMovieStart(FINAL_ARTHAS_MOVIE);
    }

    void doRevivePlayers()
    {
        Creature* pMenethil = m_creature->GetMap()->GetCreature(MenethilGUID);
        Map::PlayerList const &pList = pMenethil->GetMap()->GetPlayers();
        if (pList.isEmpty()) return;
        for (Map::PlayerList::const_iterator i = pList.begin(); i != pList.end(); ++i)
            {
               if (Player* pPlayer = i->getSource())
               {
                   if (pPlayer && !pPlayer->isAlive() && pPlayer->IsInMap(pMenethil))
                   {
                       pMenethil->CastSpell(pPlayer, SPELL_REVALL, true);
                       pPlayer->ResurrectPlayer(100, false);
                   }
                }
             };
    }

    void UpdateAI(const uint32 diff)
    {

        if (pInstance->GetData(TYPE_LICH_KING) == FAIL && m_creature->HasAura(SPELL_ICEBLOCK_TRIGGER))
        {
            m_creature->RemoveAurasDueToSpell(SPELL_ICEBLOCK_TRIGGER);
            m_creature->GetMotionMaster()->MoveTargetedHome();
            Reset();
        }

        if (pInstance->GetData(TYPE_EVENT_NPC) == NPC_TIRION)
        {
            UpdateTimer = pInstance->GetData(TYPE_EVENT_TIMER);
            if (UpdateTimer <= diff)
            {
            debug_log("EventMGR: creature %u received signal %u ",m_creature->GetEntry(),pInstance->GetData(TYPE_EVENT));
            switch (pInstance->GetData(TYPE_EVENT))
                {
                case 12030:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
                          DoScriptText(SAY_INTRO_2, m_creature);
                          UpdateTimer = 9000;
                          pInstance->SetData(TYPE_EVENT,12040);
                          break;
                case 12050:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_POINT_NOSHEATHE);
                          DoScriptText(SAY_INTRO_4, m_creature);
                          UpdateTimer = 3000;
                          pInstance->SetData(TYPE_EVENT,12051);
                          break;
                case 12051:
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                          UpdateTimer = 1000;
                          pInstance->SetData(TYPE_EVENT,12052);
                          break;
                case 12052:
                          m_creature->SetWalk(false);
                          StartMovement(3,12053);
                          break;
                case 12053:
                          UpdateTimer = 3000;
                          pInstance->SetData(TYPE_EVENT,12060);
                          m_creature->CastSpell(m_creature, SPELL_ICEBLOCK_TRIGGER, true);
                          break;
                case 13110:
                          DoScriptText(SAY_OUTRO_6, m_creature);
                          UpdateTimer = 6000;
                          m_creature->CastSpell(m_creature, SPELL_TIRION_LIGHT, false);
                          pInstance->SetData(TYPE_EVENT,13120);
                          break;
                case 13130:
                          SetCombatMovement(false);
                          m_creature->RemoveAurasDueToSpell(SPELL_ICEBLOCK_TRIGGER);
                          UpdateTimer = 500;
                          m_creature->SetOrientation(0.0f);
                          pInstance->SetData(TYPE_EVENT,13131);
                          break;
                case 13131:
                          m_creature->SetWalk(false);
                          StartMovement(2,13132);
                          break;
                case 13132:
                          StartMovement(5,13140);
                          DoScriptText(SAY_OUTRO_8, m_creature);
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                          break;
                case 13150:
                          UpdateTimer = 1000;
                          pInstance->SetData(TYPE_EVENT,13160);
                          break;
                case 13170:
                          UpdateTimer = 2000;
                          pInstance->SetData(TYPE_EVENT,13180);
                          break;
                case 13190:
                          UpdateTimer = 500;
                          pInstance->SetData(TYPE_EVENT,13200);
                          break;
                case 13210:
                          UpdateTimer = 3000;
                          pInstance->SetData(TYPE_EVENT,13230);
                          break;
                case 13230:
                          UpdateTimer = 12000;
                          {
                              Creature* pMenethil = m_creature->SummonCreature(NPC_MENETHIL, m_creature->GetPositionX()+5, m_creature->GetPositionY()+5, m_creature->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 5000);
                              MenethilGUID = pMenethil->GetObjectGuid();
                          }
                          pInstance->SetData(TYPE_EVENT,13250);
                          DoScriptText(SAY_OUTRO_9, m_creature->GetMap()->GetCreature(MenethilGUID));
                          break;
                case 13250:
                          UpdateTimer = 6000;
                          pInstance->SetData(TYPE_EVENT,13270);
                          {
                              Creature* pMenethil = m_creature->GetMap()->GetCreature(MenethilGUID);
                              DoScriptText(SAY_OUTRO_10, pMenethil);
                              pMenethil->CastSpell(pMenethil, SPELL_REVIVE_VISUAL, false);
                          }
                          doRevivePlayers();
                          break;
                case 13270:
                          UpdateTimer = 6000;
                          pInstance->SetData(TYPE_EVENT,13280);
                          if (Creature* pLichKing = pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                          {
                              m_creature->SetInCombatWith(pLichKing);
                              pLichKing->SetInCombatWith(m_creature);
                              pLichKing->AddThreat(m_creature, 1000.0f);
                              m_creature->AI()->AttackStart(pLichKing);
                              Creature* pMenethil = m_creature->GetMap()->GetCreature(MenethilGUID);
                              pMenethil->AI()->AttackStart(pLichKing);
                              SetCombatMovement(true);
                              m_creature->GetMotionMaster()->MoveChase(pLichKing);
                          };
                          break;
                case 13290:
                          UpdateTimer = 5000;
                          pInstance->SetData(TYPE_EVENT,13310);
                          break;
                case 13310:
                          UpdateTimer = 5000;
                          pInstance->SetData(TYPE_EVENT,13330);
                          break;
                case 13330:
                          UpdateTimer = 5000;
                          pInstance->SetData(TYPE_EVENT,13350);
                          break;
                case 13350:
                          UpdateTimer = 2000;
                          pInstance->SetData(TYPE_EVENT,13370);
                          break;
                case 14010:
                          m_creature->AttackStop();
                          SetCombatMovement(false);
                          UpdateTimer =90000;
                          pInstance->SetData(TYPE_EVENT,14030);
                          m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                          if (Creature* pLichKing = pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                              pLichKing->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                          doSendCinematic();
                          break;
                case 14030:
                          UpdateTimer = 20000;
                          pInstance->SetData(TYPE_EVENT,14030);
                          {
                              if (Creature* pMenethil = m_creature->GetMap()->GetCreature(MenethilGUID))
                                  if (pMenethil->isAlive())
                                      pMenethil->ForcedDespawn();
                              if (Creature* pLichKing = pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                                  pLichKing->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                          }
                          pInstance->SetData(TYPE_EVENT,0);
                          EnterEvadeMode();
                          break;
                default:
                          break;
                }
             } else UpdateTimer -= diff;
             pInstance->SetData(TYPE_EVENT_TIMER, UpdateTimer);
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
        DoMeleeAttackIfReady();
    }
};
*/
/*
bool GossipHello_boss_tirion_icc(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* pInstance;
    pInstance = (ScriptedInstance*)pCreature->GetInstanceData();

    if (pInstance->GetData(TYPE_LICH_KING) != NOT_STARTED &&
        pInstance->GetData(TYPE_LICH_KING) != FAIL )
    {
        pPlayer->PlayerTalkClass->SendGossipMenu(721002, pCreature->GetObjectGuid());
        return true;
    };

    pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, -3631608, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
    pPlayer->PlayerTalkClass->SendGossipMenu(721001, pCreature->GetObjectGuid());
    return true;
};

bool GossipSelect_boss_tirion_icc(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    ScriptedInstance* pInstance;
    pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
    if (!pInstance) return false;

    if (uiAction == GOSSIP_ACTION_INFO_DEF)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pInstance->SetData(TYPE_LICH_KING, IN_PROGRESS);
        pInstance->SetData(TYPE_EVENT,12000);
        return true;
    } else return false;
};

CreatureAI* GetAI_boss_tirion_icc(Creature* pCreature)
{
    return new boss_tirion_iccAI(pCreature);
}
*/
/*
struct MANGOS_DLL_DECL  mob_ice_sphere_iccAI : public BSWScriptedAI
{
    mob_ice_sphere_iccAI(Creature *pCreature) : BSWScriptedAI(pCreature)
    {
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance *pInstance;

    void Reset()
    {
        resetTimers();
        doCast(SPELL_ICE_SPHERE_VISUAL);
        m_creature->SetWalk(true);
    }


    void UpdateAI(const uint32 uiDiff)
    {
        if (!pInstance || pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (!hasAura(SPELL_ICE_SPHERE_VISUAL))
            doCast(SPELL_ICE_SPHERE_VISUAL);

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            {
                if (Unit* pTarget = doSelectRandomPlayerAtRange(120.0f))
                {
                   m_creature->SetInCombatWith(pTarget);
                   m_creature->AddThreat(pTarget,100.0f);
                }
            return;
            }

        if (m_creature->getVictim()->GetTypeId() != TYPEID_PLAYER)
            return;

        timedCast(SPELL_ICE_PULSE, uiDiff);

        if (m_creature->IsWithinDistInMap(m_creature->getVictim(), 1.0f))
            timedCast(SPELL_ICE_BURST,uiDiff);
    }
};

CreatureAI* GetAI_mob_ice_sphere_icc(Creature* pCreature)
{
    return new mob_ice_sphere_iccAI(pCreature);
}
*/
/*
struct MANGOS_DLL_DECL mob_defiler_iccAI : public BSWScriptedAI
{
    mob_defiler_iccAI(Creature *pCreature) : BSWScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        Reset();
    }

    ScriptedInstance *m_pInstance;
    uint32 life_timer;
    float m_Size0;
    float m_Size;

    void Reset()
    {
        SetCombatMovement(false);
        life_timer = 30000;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->CastSpell(m_creature, SPELL_DEFILE, true);
        m_Size0 = m_creature->GetFloatValue(OBJECT_FIELD_SCALE_X);
        m_Size = m_Size0;
    }

    void AttackStart(Unit *pWho)
    {
        return;
    }

    bool doSearchPlayers()
    {
        if(doSelectRandomPlayerAtRange(m_Size * 3.0f)) return true;
        else return false;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if(m_pInstance && m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        if (life_timer <= uiDiff)
            m_creature->ForcedDespawn();
        else life_timer -= uiDiff;

        if (doSearchPlayers() && m_Size <= m_Size0 * 6.0f) {
                m_Size = m_Size*1.01;
                m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, m_Size);
                }

    }

}

CreatureAI* GetAI_mob_defiler_icc(Creature* pCreature)
{
    return new mob_defiler_iccAI(pCreature);
}
*/
/*
struct MANGOS_DLL_DECL mob_strangulate_vehicleAI : public ScriptedAI
{
    mob_strangulate_vehicleAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        Reset();
    }

    ScriptedInstance *m_pInstance;

    void Reset()
    {
        SetCombatMovement(false);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void AttackStart(Unit *pWho)
    {
        return;
    }

    void UpdateAI(const uint32 uiDiff)
    {
       m_creature->ForcedDespawn();
    }

};

CreatureAI* GetAI_mob_strangulate_vehicle(Creature* pCreature)
{
    return new mob_strangulate_vehicleAI(pCreature);
}
*/
/*
struct MANGOS_DLL_DECL  mob_vile_spiritAI : public BSWScriptedAI
{
    mob_vile_spiritAI(Creature *pCreature) : BSWScriptedAI(pCreature)
    {
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance *pInstance;
    bool movementstarted;

    void Reset()
    {
       resetTimers();
       if (Unit* pTarget = doSelectRandomPlayerAtRange(120.0f))
           {
               m_creature->SetInCombatWith(pTarget);
               m_creature->AddThreat(pTarget,1000.0f);
           }
       SetCombatMovement(false);
       movementstarted = false;
       m_creature->SetWalk(true);
    }


    void UpdateAI(const uint32 uiDiff)
    {
        if (!pInstance || pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (timedQuery(SPELL_SPIRITS_BURST, uiDiff) && !movementstarted)
        {
           SetCombatMovement(true);
           m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
           movementstarted = true;
        }

        if (m_creature->getVictim()->GetTypeId() != TYPEID_PLAYER)
            return;

        if (m_creature->IsWithinDistInMap(m_creature->getVictim(), 1.0f))
        {
            doCast(SPELL_SPIRITS_BURST);
            m_creature->ForcedDespawn();
        };
    }
};

CreatureAI* GetAI_mob_vile_spirit(Creature* pCreature)
{
    return new mob_vile_spiritAI(pCreature);
}
*/
/*
struct MANGOS_DLL_DECL  mob_raging_spiritAI : public BSWScriptedAI
{
    mob_raging_spiritAI(Creature *pCreature) : BSWScriptedAI(pCreature)
    {
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance *pInstance;

    void Reset()
    {
        resetTimers();
        m_creature->SetDisplayId(10771);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!pInstance || pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

            timedCast(SPELL_SOUL_SHRIEK, uiDiff);
    }
};

CreatureAI* GetAI_mob_raging_spirit(Creature* pCreature)
{
    return new mob_raging_spiritAI(pCreature);
}
*/

void AddSC_boss_lich_king_icc()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_the_lich_king_icc";
    newscript->GetAI = &GetAI_boss_the_lich_king_icc;
    newscript->RegisterSelf();
/*
    newscript = new Script;
    newscript->Name = "boss_tirion_icc";
    newscript->GetAI = &GetAI_boss_tirion_icc;
    newscript->pGossipHello = &GossipHello_boss_tirion_icc;
    newscript->pGossipSelect = &GossipSelect_boss_tirion_icc;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_ice_sphere_icc";
    newscript->GetAI = &GetAI_mob_ice_sphere_icc;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_defiler_icc";
    newscript->GetAI = &GetAI_mob_defiler_icc;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_strangulate_vehicle";
    newscript->GetAI = &GetAI_mob_strangulate_vehicle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_vile_spirit";
    newscript->GetAI = &GetAI_mob_vile_spirit;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_raging_spirit";
    newscript->GetAI = &GetAI_mob_raging_spirit;
    newscript->RegisterSelf();
*/
}

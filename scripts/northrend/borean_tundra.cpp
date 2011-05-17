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

/* ScriptData
SDName: Borean_Tundra
SD%Complete: 100
SDComment: Quest support: 11570, 11590, 11692, 11676, 11708, 11919, 11940, 11961. Taxi vendors. 
SDCategory: Borean Tundra
EndScriptData */

/* ContentData
npc_fizzcrank_fullthrottle
npc_iruk
npc_kara_thricestar
npc_nesingwary_trapper
go_caribou_trap
npc_sinkhole_kill_credit
npc_surristrasz
npc_tiare
npc_lurgglbr
npc_nexus_drake
go_scourge_cage
npc_beryl_sorcerer
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"
#include "ObjectMgr.h"
#include "follower_ai.h"

/*######
## npc_fizzcrank_fullthrottle
######*/

#define GOSSIP_ITEM_GO_ON   "Go on."
#define GOSSIP_ITEM_TELL_ME "Tell me what's going on out here, Fizzcrank."

enum
{
    GOSSIP_TEXTID_FIZZCRANK1    = 12456,
    GOSSIP_TEXTID_FIZZCRANK2    = 12457,
    GOSSIP_TEXTID_FIZZCRANK3    = 12458,
    GOSSIP_TEXTID_FIZZCRANK4    = 12459,
    GOSSIP_TEXTID_FIZZCRANK5    = 12460,
    GOSSIP_TEXTID_FIZZCRANK6    = 12461,
    GOSSIP_TEXTID_FIZZCRANK7    = 12462,
    GOSSIP_TEXTID_FIZZCRANK8    = 12463,
    GOSSIP_TEXTID_FIZZCRANK9    = 12464,

    QUEST_THE_MECHAGNOMES       = 11708
};

bool GossipHello_npc_fizzcrank_fullthrottle(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetObjectGuid());

    if (pPlayer->GetQuestStatus(QUEST_THE_MECHAGNOMES) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELL_ME, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_fizzcrank_fullthrottle(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK1, pCreature->GetObjectGuid());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK2, pCreature->GetObjectGuid());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK3, pCreature->GetObjectGuid());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK4, pCreature->GetObjectGuid());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK5, pCreature->GetObjectGuid());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK6, pCreature->GetObjectGuid());
            break;
        case GOSSIP_ACTION_INFO_DEF+7:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK7, pCreature->GetObjectGuid());
            break;
        case GOSSIP_ACTION_INFO_DEF+8:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK8, pCreature->GetObjectGuid());
            break;
        case GOSSIP_ACTION_INFO_DEF+9:
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK9, pCreature->GetObjectGuid());
            pPlayer->AreaExploredOrEventHappens(QUEST_THE_MECHAGNOMES);
            break;
    }
    return true;
}

/*######
## npc_iruk
######*/

#define GOSSIP_ITEM_IRUK        "<Search corpse for Issliruk's Totem.>"

enum
{
    QUEST_SPIRITS_WATCH_OVER_US     = 11961,
    SPELL_CREATE_TOTEM              = 46816
};

bool GossipHello_npc_iruk(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_SPIRITS_WATCH_OVER_US) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_IRUK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_iruk(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer,SPELL_CREATE_TOTEM,true);
    }

    return true;
}

/*######
## npc_kara_thricestar
######*/

#define GOSSIP_ITEM_THRICESTAR1      "Do you think I could take a ride on one of those flying machines?"
#define GOSSIP_ITEM_THRICESTAR2      "Kara, I need to be flown out the Dens of Dying to find Bixie."

enum
{
    QUEST_CHECK_IN_WITH_BIXIE       = 11692,
    SPELL_FIZZCRANK_AIRSTRIP        = 51446
};

bool GossipHello_npc_kara_thricestar(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isTaxi())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, GOSSIP_ITEM_THRICESTAR1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    if (pPlayer->GetQuestStatus(QUEST_CHECK_IN_WITH_BIXIE) == QUEST_STATUS_COMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_THRICESTAR2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_kara_thricestar(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->GetSession()->SendTaxiMenu(pCreature);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_FIZZCRANK_AIRSTRIP, false);
            break;
    }

    return true;
}

/*######
## npc_nesingwary_trapper
######*/

enum
{
    NPC_NESINGWARY_TRAPPER  = 25835,
    GO_QUALITY_FUR          = 187983,

    SAY_PHRASE_1            = -1000599,
    SAY_PHRASE_2            = -1000600,
    SAY_PHRASE_3            = -1000601,
    SAY_PHRASE_4            = -1000602
};

struct MANGOS_DLL_DECL npc_nesingwary_trapperAI : public ScriptedAI
{
    npc_nesingwary_trapperAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint8 m_uiPhase;
    uint32 m_uiPhaseTimer;
    ObjectGuid m_playerGuid;
    ObjectGuid m_trapGuid;

    void Reset()
    {
        m_uiPhase = 0;
        m_uiPhaseTimer = 0;
        m_playerGuid.Clear();
        m_trapGuid.Clear();
    }

    void StartAction(Player* pPlayer, GameObject* pTrap)
    {
        m_uiPhase = 1;
        m_uiPhaseTimer = 3000;
        m_playerGuid = pPlayer->GetObjectGuid();
        m_trapGuid = pTrap->GetObjectGuid();

        switch (urand(0, 3))
        {
            case 0: DoScriptText(SAY_PHRASE_1, m_creature); break;
            case 1: DoScriptText(SAY_PHRASE_2, m_creature); break;
            case 2: DoScriptText(SAY_PHRASE_3, m_creature); break;
            case 3: DoScriptText(SAY_PHRASE_4, m_creature); break;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!m_creature->getVictim() && m_uiPhase)
        {
            if (m_uiPhaseTimer <= uiDiff)
            {
                switch(m_uiPhase)
                {
                    case 1:
                        if (GameObject* pTrap = m_creature->GetMap()->GetGameObject(m_trapGuid))
                        {
                            if (pTrap->isSpawned())
                                m_creature->GetMotionMaster()->MovePoint(0, pTrap->GetPositionX(), pTrap->GetPositionY(), pTrap->GetPositionZ());
                        }
                        break;
                    case 2:
                        if (GameObject* pTrap = m_creature->GetMap()->GetGameObject(m_trapGuid))
                        {
                            if (pTrap->isSpawned())
                            {
                                pTrap->Use(m_creature);

                                if (Player* pPlayer = m_creature->GetMap()->GetPlayer(m_playerGuid))
                                {
                                    if (pPlayer->isAlive())
                                        pPlayer->KilledMonsterCredit(m_creature->GetEntry());
                                }
                            }
                        }
                        break;
                }

                m_uiPhase = 0;
            }
            else
                m_uiPhaseTimer -= uiDiff;
        }
    }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        m_creature->HandleEmote(EMOTE_ONESHOT_LOOT);
        m_uiPhaseTimer = 2000;
        m_uiPhase = 2;
    }
};

CreatureAI* GetAI_npc_nesingwary_trapper(Creature* pCreature)
{
    return new npc_nesingwary_trapperAI(pCreature);
}

/*#####
# npc_oil_stained_wolf
#####*/

enum
{
    SPELL_THROW_WOLF_BAIT           = 53326,
    SPELL_PLACE_WOLF_BAIT           = 46072,                // doesn't appear to be used for anything
    SPELL_HAS_EATEN                 = 46073,
    SPELL_SUMMON_DROPPINGS          = 46075,

    FACTION_MONSTER                 = 634,

    POINT_DEST                      = 1
};

struct MANGOS_DLL_DECL npc_oil_stained_wolfAI : public ScriptedAI
{
    npc_oil_stained_wolfAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    bool m_bCanCrapInPublic;
    uint32 m_uiPooTimer;

    void Reset()
    {
        m_bCanCrapInPublic = false;
        m_uiPooTimer = 0;
    }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (uiPointId == POINT_DEST)
        {
            DoCastSpellIfCan(m_creature, SPELL_HAS_EATEN);
            m_uiPooTimer = 4000;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
        {
            if (m_uiPooTimer)
            {
                if (m_uiPooTimer <= uiDiff)
                {
                    if (m_bCanCrapInPublic)
                    {
                        DoCastSpellIfCan(m_creature, SPELL_SUMMON_DROPPINGS);
                        m_creature->GetMotionMaster()->Clear();
                        Reset();
                    }
                    else
                    {
                        m_creature->HandleEmote(EMOTE_ONESHOT_BATTLEROAR);
                        m_bCanCrapInPublic = true;
                        m_uiPooTimer = 3000;
                    }
                }
                else
                    m_uiPooTimer -= uiDiff;
            }

            return;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_oil_stained_wolf(Creature* pCreature)
{
    return new npc_oil_stained_wolfAI(pCreature);
}

bool EffectDummyCreature_npc_oil_stained_wolf(Unit* pCaster, uint32 uiSpellId, SpellEffectIndex uiEffIndex, Creature* pCreatureTarget)
{
    if (uiSpellId == SPELL_THROW_WOLF_BAIT)
    {
        if (uiEffIndex == EFFECT_INDEX_0 && pCreatureTarget->getFaction() != FACTION_MONSTER && !pCreatureTarget->HasAura(SPELL_HAS_EATEN))
        {
            pCreatureTarget->SetFactionTemporary(FACTION_MONSTER);
            pCreatureTarget->RemoveSplineFlag(SPLINEFLAG_WALKMODE);

            pCreatureTarget->GetMotionMaster()->MoveIdle();

            float fX, fY, fZ;
            pCaster->GetContactPoint(pCreatureTarget, fX, fY, fZ, CONTACT_DISTANCE);
            pCreatureTarget->GetMotionMaster()->MovePoint(POINT_DEST, fX, fY, fZ);
            return true;
        }
    }

    return false;
}

bool EffectAuraDummy_npc_oil_stained_wolf(const Aura* pAura, bool bApply)
{
    if (pAura->GetId() == SPELL_HAS_EATEN)
    {
        if (pAura->GetEffIndex() != EFFECT_INDEX_0)
            return false;

        if (bApply)
        {
            pAura->GetTarget()->HandleEmote(EMOTE_ONESHOT_CUSTOMSPELL01);
        }
        else
        {
            Creature* pCreature = (Creature*)pAura->GetTarget();
            pCreature->setFaction(pCreature->GetCreatureInfo()->faction_A);
        }

        return true;
    }

    return false;
}

/*######
## go_caribou_trap
######*/

bool GOUse_go_caribou_trap(Player* pPlayer, GameObject* pGo)
{
    float fX, fY, fZ;
    pGo->GetClosePoint(fX, fY, fZ, pGo->GetObjectBoundingRadius(), 2*INTERACTION_DISTANCE, frand(0, M_PI_F*2));

    if (Creature* pCreature = pGo->SummonCreature(NPC_NESINGWARY_TRAPPER, fX, fY, fZ, pGo->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10000))
    {
        if (npc_nesingwary_trapperAI* pTrapperAI = dynamic_cast<npc_nesingwary_trapperAI*>(pCreature->AI()))
            pTrapperAI->StartAction(pPlayer, pGo);

        pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);

        if (GameObject* pGoFur = GetClosestGameObjectWithEntry(pGo, GO_QUALITY_FUR, INTERACTION_DISTANCE))
        {
            if (!pGoFur->isSpawned())
            {
                pGoFur->SetRespawnTime(10);
                pGoFur->Refresh();
            }
        }
    }

    return true;
}
/*#####
# npc_sinkhole_kill_credit
#####*/

enum
{
    SPELL_SUMMON_EXPLOSIVES_CART_FIRE   = 46799,
    SPELL_SUMMON_SCOURGE_BURROWER       = 46800,
    SPELL_COSMETIC_HUGE_EXPLOSION       = 46225,
    SPELL_CANNON_FIRE                   = 42445,
};

struct MANGOS_DLL_DECL npc_sinkhole_kill_creditAI : public ScriptedAI
{
    npc_sinkhole_kill_creditAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    ObjectGuid m_uiCartGUID;
    ObjectGuid m_uiWormGUID;
    uint32 m_uiCartTimer;
    uint32 m_uiCartPhase;

    void Reset()
    {
        m_uiCartGUID.Clear();
        m_uiWormGUID.Clear();
        m_uiCartTimer = 2000;
        m_uiCartPhase = 0;
    }

    void JustSummoned(Creature* pSummoned)
    {
        m_uiWormGUID = pSummoned->GetObjectGuid();
    }

    void JustSummoned(GameObject* pGo)
    {
        // Go is not really needed, but ok to use as a check point so only one "event" can be processed at a time
        if (!m_uiCartGUID.IsEmpty())
            return;

        // Expecting summoned from mangos dummy effect 46797
        m_uiCartGUID = pGo->GetObjectGuid();
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!m_uiCartGUID.IsEmpty())
        {
            if (m_uiCartTimer <= uiDiff)
            {
                switch(m_uiCartPhase)
                {
                    case 0:
                        DoCastSpellIfCan(m_creature, SPELL_SUMMON_EXPLOSIVES_CART_FIRE);
                        m_uiCartTimer = 4000;
                        break;
                    case 1:
                        // Unclear if these should be in a dummy effect or not.
                        // The order of spells are correct though.
                        DoCastSpellIfCan(m_creature, SPELL_COSMETIC_HUGE_EXPLOSION, CAST_TRIGGERED);
                        DoCastSpellIfCan(m_creature, SPELL_CANNON_FIRE, CAST_TRIGGERED);
                        break;
                    case 2:
                        DoCastSpellIfCan(m_creature, SPELL_SUMMON_SCOURGE_BURROWER);
                        m_uiCartTimer = 2000;
                        break;
                    case 3:
                        if (Creature* pWorm = m_creature->GetMap()->GetCreature(m_uiWormGUID))
                        {
                            pWorm->SetDeathState(JUST_DIED);
                            pWorm->SetHealth(0);
                        }
                        m_uiCartTimer = 10000;
                        break;
                    case 4:
                        if (Creature* pWorm = m_creature->GetMap()->GetCreature(m_uiWormGUID))
                            pWorm->RemoveCorpse();

                        Reset();
                        return;
                }

                ++m_uiCartPhase;
            }
            else
                m_uiCartTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_npc_sinkhole_kill_credit(Creature* pCreature)
{
    return new npc_sinkhole_kill_creditAI(pCreature);
}

/*######
## npc_surristrasz
######*/

#define GOSSIP_ITEM_FREE_FLIGHT "I'd like passage to the Transitus Shield."
#define GOSSIP_ITEM_FLIGHT      "May I use a drake to fly elsewhere?"

enum
{
    SPELL_ABMER_TO_COLDARRA     = 46064
};

bool GossipHello_npc_surristrasz(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetObjectGuid());

    if (pCreature->isTaxi())
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FREE_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_GOSSIP);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, GOSSIP_ITEM_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_TAXIVENDOR);
    }

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_surristrasz(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_OPTION_GOSSIP)
    {
        pPlayer->CLOSE_GOSSIP_MENU();

        //TaxiPath 795 (amber to coldarra)
        pPlayer->CastSpell(pPlayer, SPELL_ABMER_TO_COLDARRA, true);
    }

    if (uiAction == GOSSIP_OPTION_TAXIVENDOR)
        pPlayer->GetSession()->SendTaxiMenu(pCreature);

    return true;
}

/*######
## npc_tiare
######*/

#define GOSSIP_ITEM_TELEPORT    "Teleport me to Amber Ledge, please."

enum
{
    SPELL_TELEPORT_COLDARRA     = 50135
};

bool GossipHello_npc_tiare(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELEPORT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_GOSSIP);
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_tiare(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_OPTION_GOSSIP)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer, SPELL_TELEPORT_COLDARRA, true);
    }
    return true;
}

/*######
## npc_lurgglbr
######*/

enum
{
    QUEST_ESCAPE_FROM_WINTERFIN_CAVERNS = 11570,
    GO_CAGE                             = 187369,

    SAY_START_1                         = -1000575,
    SAY_START_2                         = -1000576,
    SAY_END_1                           = -1000577,
    SAY_END_2                           = -1000578
};

struct MANGOS_DLL_DECL npc_lurgglbrAI : public npc_escortAI
{
    npc_lurgglbrAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_uiSayTimer = 0;
        m_uiSpeech = 0;
        Reset();
    }

    uint32 m_uiSayTimer;
    uint8 m_uiSpeech;

    void Reset()
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            m_uiSayTimer = 0;
            m_uiSpeech = 0;
        }
    }

    void JustStartedEscort()
    {
        if (GameObject* pCage = GetClosestGameObjectWithEntry(m_creature, GO_CAGE, INTERACTION_DISTANCE))
        {
            if (pCage->GetGoState() == GO_STATE_READY)
                pCage->Use(m_creature);
        }
    }

    void WaypointStart(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 1:
                if (Player* pPlayer = GetPlayerForEscort())
                    DoScriptText(SAY_START_2, m_creature, pPlayer);

                // Cage actually closes here, however it's normally determined by GO template and auto close time

                break;
        }
    }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 0:
                if (Player* pPlayer = GetPlayerForEscort())
                {
                    m_creature->SetFacingToObject(pPlayer);
                    DoScriptText(SAY_START_1, m_creature, pPlayer);
                }
                break;
            case 25:
                if (Player* pPlayer = GetPlayerForEscort())
                {
                    DoScriptText(SAY_END_1, m_creature, pPlayer);
                    m_uiSayTimer = 3000;
                }
                break;
        }
    }

    void UpdateEscortAI(const uint32 uiDiff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
        {
            if (m_uiSayTimer)
            {
                if (m_uiSayTimer <= uiDiff)
                {
                    Player* pPlayer = GetPlayerForEscort();

                    if (!pPlayer)
                    {
                        m_uiSayTimer = 0;
                        return;
                    }

                    m_creature->SetFacingToObject(pPlayer);

                    switch(m_uiSpeech)
                    {
                        case 0:
                            DoScriptText(SAY_END_2, m_creature, pPlayer);
                            m_uiSayTimer = 3000;
                            break;
                        case 1:
                            pPlayer->GroupEventHappens(QUEST_ESCAPE_FROM_WINTERFIN_CAVERNS, m_creature);
                            m_uiSayTimer = 0;
                            break;
                    }

                    ++m_uiSpeech;
                }
                else
                    m_uiSayTimer -= uiDiff;
            }

            return;
        }

        DoMeleeAttackIfReady();
    }
};

bool QuestAccept_npc_lurgglbr(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ESCAPE_FROM_WINTERFIN_CAVERNS)
    {
        if (npc_lurgglbrAI* pEscortAI = dynamic_cast<npc_lurgglbrAI*>(pCreature->AI()))
        {
            pCreature->setFaction(FACTION_ESCORT_N_NEUTRAL_PASSIVE);
            pEscortAI->Start(false, pPlayer, pQuest);
        }
    }
    return true;
}

CreatureAI* GetAI_npc_lurgglbr(Creature* pCreature)
{
    return new npc_lurgglbrAI(pCreature);
}

/*######
## npc_nexus_drake_hatchling
######*/

enum
{
    SPELL_DRAKE_HARPOON             = 46607,
    SPELL_RED_DRAGONBLOOD           = 46620,
    SPELL_DRAKE_HATCHLING_SUBDUED   = 46691,
    SPELL_SUBDUED                   = 46675,

    NPC_RAELORASZ                   = 26117,
    DRAKE_HUNT_KILL_CREDIT          = 26175,

    QUEST_DRAKE_HUNT                = 11919,
    QUEST_DRAKE_HUNT_D              = 11940

};

struct MANGOS_DLL_DECL npc_nexus_drakeAI : public FollowerAI
{
    npc_nexus_drakeAI(Creature* pCreature) : FollowerAI(pCreature) { Reset(); }
    
     uint64 uiHarpoonerGUID;
     bool bWithRedDragonBlood;
     bool bIsFollowing;

     void Reset()
     {
         bWithRedDragonBlood = false;
         bIsFollowing = false;
     }

     void EnterCombat(Unit* pWho)
     {
         AttackStart(pWho);
     }
     
     void SpellHit(Unit* pCaster, SpellEntry const* pSpell)
     {
            if (pSpell->Id == SPELL_DRAKE_HARPOON && pCaster->GetTypeId() == TYPEID_PLAYER)
            {
                uiHarpoonerGUID = pCaster->GetGUID();
                DoCast(m_creature, SPELL_RED_DRAGONBLOOD, true);
            }
            m_creature->Attack(pCaster,true);
            bWithRedDragonBlood = true;
     }

     void MoveInLineOfSight(Unit *pWho)
     {
         FollowerAI::MoveInLineOfSight(pWho);


         if (pWho->GetEntry() == NPC_RAELORASZ && m_creature->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
         {
           if (Player *pHarpooner = m_creature->GetMap()->GetPlayer(uiHarpoonerGUID))
                 {
                    
                     pHarpooner->KilledMonsterCredit(DRAKE_HUNT_KILL_CREDIT,m_creature->GetGUID());
                     pHarpooner->RemoveAurasByCasterSpell(SPELL_DRAKE_HATCHLING_SUBDUED,uiHarpoonerGUID);
                     SetFollowComplete();
                     uiHarpoonerGUID = 0;
                     m_creature->ForcedDespawn(1000);
                 }
              
          }
      }
     
     void UpdateAI(const uint32 uidiff)
        {
            if (bWithRedDragonBlood && uiHarpoonerGUID && !m_creature->HasAura(SPELL_RED_DRAGONBLOOD))
            {
                if (Player *pHarpooner = m_creature->GetMap()->GetPlayer(uiHarpoonerGUID))
                {
                    EnterEvadeMode();
                    StartFollow(pHarpooner, 35, NULL);

                    DoCast(m_creature, SPELL_SUBDUED, true);
                    pHarpooner->CastSpell(pHarpooner, SPELL_DRAKE_HATCHLING_SUBDUED, true);

                    m_creature->AttackStop();
                    bIsFollowing = true;
                    bWithRedDragonBlood = false;
                }
            }
            if(bIsFollowing && !m_creature->HasAura(SPELL_SUBDUED))
            {
                m_creature->ForcedDespawn(1000);
            }

            if (!m_creature->getVictim())
                return;

            DoMeleeAttackIfReady();
        }
};

CreatureAI* GetAI_npc_nexus_drake(Creature* pCreature)
{
    return new npc_nexus_drakeAI(pCreature);
}

/*#####
## go_scourge_cage
#####*/

enum
{
    QUEST_MERCIFUL_FREEDOM      =  11676,
    NPC_SCOURGE_PRISONER        =  25610,
};

bool GOHello_go_scourge_cage(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->GetQuestStatus(QUEST_MERCIFUL_FREEDOM) == QUEST_STATUS_INCOMPLETE)
    {
        Creature *pCreature = GetClosestCreatureWithEntry(pGo, NPC_SCOURGE_PRISONER, INTERACTION_DISTANCE);
        if(pCreature)
        {
            pPlayer->KilledMonsterCredit(NPC_SCOURGE_PRISONER, pCreature->GetGUID());
            pCreature->CastSpell(pCreature, 43014, false);
        }
    }
    return false;
};

/*######
## npc_beryl_sorcerer
######*/

enum eBerylSorcerer
{
    NPC_CAPTURED_BERLY_SORCERER         = 25474,
    NPC_LIBRARIAN_DONATHAN              = 25262,

    SPELL_ARCANE_CHAINS                 = 45611,
    SPELL_COSMETIC_CHAINS               = 54324,
    SPELL_COSMETIC_ENSLAVE_CHAINS_SELF  = 45631
};

struct MANGOS_DLL_DECL npc_beryl_sorcererAI : public FollowerAI
{
    npc_beryl_sorcererAI(Creature* pCreature) : FollowerAI(pCreature) { 
        Reset(); 
    }

    bool bEnslaved;
    uint64 uiChainerGUID;
    uint32 m_uiNormalFaction;

    void Reset()
    {
         m_creature->setFaction(14);
         bEnslaved = false;
    }
    void EnterCombat(Unit* pWho)
    {
            AttackStart(pWho);
    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell)
    {
        if (pSpell->Id == SPELL_ARCANE_CHAINS && pCaster->GetTypeId() == TYPEID_PLAYER && !bEnslaved)
            {
                EnterEvadeMode(); //We make sure that the npc is not attacking the player!
                m_creature->setFaction(35);
                uiChainerGUID = pCaster->GetGUID();
                if(Player *pChainer = m_creature->GetMap()->GetPlayer(uiChainerGUID))
                {
                StartFollow(pChainer, 35, NULL);
                m_creature->UpdateEntry(NPC_CAPTURED_BERLY_SORCERER);
                DoCast(m_creature, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF, true);
 
                bEnslaved = true;
                }
            }
    }

    void MoveInLineOfSight(Unit* pWho)
    {
            FollowerAI::MoveInLineOfSight(pWho);

            if (pWho->GetEntry() == NPC_LIBRARIAN_DONATHAN && m_creature->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
            {
                if(Player *pChainer = m_creature->GetMap()->GetPlayer(uiChainerGUID))
                {
                    pChainer->KilledMonsterCredit(NPC_CAPTURED_BERLY_SORCERER,m_creature->GetGUID());
                    SetFollowComplete();
                    m_creature->ForcedDespawn(1000);
                }
            }
     }
    void UpdateAI(const uint32 uiDiff)
    {
        if (!m_creature->getVictim())
                return;

            DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_npc_beryl_sorcerer(Creature* pCreature)
{
    return new npc_beryl_sorcererAI(pCreature);
}

/**** Quest: Last Rites ****/
enum
{
    /************* Speech and Sounds ***********************/
    SAY_DIA01 = -1534071,
    SAY_DIA02 = -1534072,
    SAY_DIA03 = -1534073,
    SAY_DIA04 = -1534074,
    SAY_DIA05 = -1534075,
    SAY_DIA06 = -1534076,
    SAY_DIA07 = -1534077,
    SAY_DIA08 = -1534078,
    SAY_DIA09 = -1534079,
    SAY_DIA10 = -1534080,
    SAY_DIA11 = -1534081,
    SAY_DIA12 = -1534082,
    SAY_DIA13 = -1534083,
    SAY_DIA14 = -1534084,
    SAY_DIA15 = -1534085,
    SAY_DIA16 = -1534086,
    SAY_DIA17 = -1534087,
    SAY_DIA18 = -1534088,
    SAY_DIA19 = -1534089,
    SAY_DIA20 = -1534090,

    /************* Npc's ***********************/
    NPC_THASSARIAN = 26170,
    NPC_LICH_KING = 26203,
    NPC_LERYSSA = 25251,
    NPC_ARLOS = 25250,
    NPC_VALANAR = 28189,
    NPC_VISUAL_FORM = 25301,

    /************* Other's ***********************/
    QUEST_LAST_RITES = 12019,
    STAFF_ID = 485,
    AREA_ID = 4128,
};

#define GOSSIP_ITEM_T "Let's do this, Thassarian. It's now or never."

struct MANGOS_DLL_DECL npc_thassarianAI : public ScriptedAI
{
    npc_thassarianAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiStepTimer;
    uint32 m_uiStep;

    uint64 m_uiValanarGUID;
    uint64 m_uiLichKingGUID;
    uint64 m_uiLeryssaGUID;
    uint64 m_uiArlosGUID;

    void Reset()
    {
        m_uiValanarGUID = 0;
        m_uiLichKingGUID = 0;
        m_uiLeryssaGUID = 0;
        m_uiArlosGUID = 0;
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        if (m_creature->GetAreaId() == AREA_ID)
            m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        m_uiStep = 0;
        m_uiStepTimer = 100;
    }

    void JustDied(Unit* pKiller)
    {
        if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
Kill(Leryssa);
        if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
            Kill(Arlos);
        if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
            Valanar->RemoveFromWorld();
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);

        m_creature->SetLootRecipient(NULL);

        if (m_creature->isAlive() && m_uiStep > 20)
        {
            m_creature->GetMotionMaster()->MoveTargetedHome();
            Reset();
        }
    }

    void StartEvent(uint8 EventId)
    {
        m_uiStep = EventId;
        m_uiStepTimer = 100;
    }

    void JumpNextStep(uint32 Time)
    {
        m_uiStepTimer = Time;
        m_uiStep++;
    }

    void Kill(Unit* Oo)
    {
        Oo->DealDamage(Oo, Oo->GetMaxHealth() ,NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
    }

    void Event()
    {
        switch(m_uiStep)
        {
            case 1:
               m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
               m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
               m_creature->AddSplineFlag(SPLINEFLAG_WALKMODE);
               m_creature->GetMotionMaster()->MovePoint(0, 3712.466f, 3570.2911f, 477.443f);
               JumpNextStep(4000);
               break;
            case 2:
               m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
               if (Creature* LichKing = m_creature->SummonCreature(NPC_LICH_KING,3730.15f,3519.43f,473.32f,1.37f,TEMPSUMMON_CORPSE_TIMED_DESPAWN,30))
               {
                   m_uiLichKingGUID = LichKing->GetGUID();
                   LichKing->GetMotionMaster()->MovePoint(0, 3738.691f, 3564.734f, 477.442f);
               }
               JumpNextStep(3000);
               break;
            case 3:
               if (Creature* Valanar = m_creature->SummonCreature(NPC_VALANAR,3748.80f,3615.27f,473.3232f,4.50f,TEMPSUMMON_CORPSE_TIMED_DESPAWN,60000))
               {
                   m_uiValanarGUID = Valanar->GetGUID();
                   Valanar->SetRespawnDelay(DAY);
                   Valanar->GetMotionMaster()->MovePoint(0, 3739.823f, 3570.564f, 477.442f);
                   ((Creature*)Valanar)->UpdateEntry(NPC_VISUAL_FORM, HORDE); //huck! Replace spell (spell "Valanar Transformation" don't work!) He must update Valanar Entry and Change Name!
                   Valanar->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                   Valanar->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                   Valanar->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(0));
               }
               JumpNextStep(20000);
               break;
            case 4:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
               {
                   ((Creature*)Valanar)->UpdateEntry(NPC_VALANAR);
                   Valanar->SetStandState(UNIT_STAND_STATE_KNEEL);
                   ((Creature*)Valanar)->LoadEquipment(STAFF_ID);
                   DoScriptText(SAY_DIA01, Valanar);
               }
               if (Creature* Leryssa = m_creature->SummonCreature(NPC_LERYSSA,3753.105f,3614.296f,473.32f,1.37f,TEMPSUMMON_CORPSE_TIMED_DESPAWN,10))
               {
                   m_uiLeryssaGUID = Leryssa->GetGUID();
                   Leryssa->GetMotionMaster()->MovePoint(0, 3745.636f, 3572.464f, 477.442f);
                   Leryssa->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                   Leryssa->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
               }
               if (Creature* Arlos = m_creature->SummonCreature(NPC_ARLOS,3744.82f,3616.11f,473.32f,1.37f,TEMPSUMMON_CORPSE_TIMED_DESPAWN,10))
               {
                   m_uiArlosGUID = Arlos->GetGUID();
                   Arlos->GetMotionMaster()->MovePoint(0, 3734.854f, 3573.028f, 477.442f);
                   Arlos->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                   Arlos->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
               }
               JumpNextStep(8000);
               break;
            case 5:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
DoScriptText(SAY_DIA02, Valanar);
               JumpNextStep(11000);
               break;
            case 6:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
                   Leryssa->CastSpell(Leryssa,45066,false);
               if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
                   Arlos->CastSpell(Arlos,45066,false);
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   DoScriptText(SAY_DIA03, LichKing);
               JumpNextStep(9000);
               break;
            case 7:
               m_creature->RemoveSplineFlag(SPLINEFLAG_WALKMODE);
               m_creature->GetMotionMaster()->MovePoint(0, 3722.271f, 3566.878f, 477.442f);
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   m_creature->SetFacingToObject(LichKing);
               DoScriptText(SAY_DIA04, m_creature);
               JumpNextStep(2000);
               break;
            case 8:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
                   Valanar->SetStandState(UNIT_STAND_STATE_STAND);
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   LichKing->SetFacingToObject(m_creature);
               DoScriptText(SAY_DIA05, m_creature);
               JumpNextStep(6000);
               break;
            case 9:
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   DoScriptText(SAY_DIA06, LichKing);
               JumpNextStep(17000);
               break;
            case 10:
               DoScriptText(SAY_DIA07, m_creature);
               JumpNextStep(9000);
               break;
            case 11:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
                   DoScriptText(SAY_DIA08, Valanar);
               JumpNextStep(6000);
               break;
            case 12:
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
               {
                   if(Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
                   {
                       LichKing->SetFacingToObject(Valanar);
DoScriptText(SAY_DIA09, LichKing);
                   }
               }
               JumpNextStep(4000);
               break;
            case 13:
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   LichKing->SetFacingToObject(m_creature);
               JumpNextStep(500);
               break;
            case 14:
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   LichKing->HandleEmoteCommand(25);
               JumpNextStep(5500);
               break;
            case 15:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
               {
                   DoScriptText(SAY_DIA10, Valanar);
                   Valanar->SetFacingToObject(m_creature);
                   Valanar->setFaction(14);
                   m_creature->AI()->AttackStart(Valanar);
               }
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
Kill(LichKing);
               JumpNextStep(500);
               break;
case 17:
               EnterEvadeMode();
               m_creature->GetMotionMaster()->MovePoint(0, 3721.361f, 3566.910f, 477.442f);
               m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, UNIT_STAND_STATE_STAND);
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
               {
                   DoScriptText(SAY_DIA14, Leryssa);
                   Leryssa->RemoveAurasDueToSpell(45066);
               }
               if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
                   DoScriptText(SAY_DIA11, Arlos);
               JumpNextStep(3000);
               break;
            case 18:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
               {
                   ((Creature*)Leryssa)->RemoveSplineFlag(SPLINEFLAG_WALKMODE);
                   Leryssa->GetMotionMaster()->MovePoint(0, 3726.749f, 3568.097f, 477.442f);
                   Leryssa->SetFacingToObject(m_creature);
                   Leryssa->SetStandState(UNIT_STAND_STATE_SIT);
                   m_creature->SetFacingToObject(Leryssa);
                   m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
               }
               if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
               {
                   DoScriptText(SAY_DIA12, Arlos);
                   Arlos->RemoveAurasDueToSpell(45066);
                   Arlos->SetStandState(UNIT_STAND_STATE_DEAD);
               }
               JumpNextStep(5000);
               break;
            case 19:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
                   DoScriptText(SAY_DIA15, Leryssa);
               JumpNextStep(5000);
               break;
            case 20:
               DoScriptText(SAY_DIA13, m_creature);
               JumpNextStep(3000);
               break;
            case 21:
               DoScriptText(SAY_DIA16, m_creature);
               JumpNextStep(6000);
               break;
            case 22:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
                   DoScriptText(SAY_DIA17, Leryssa);
               JumpNextStep(9000);
               break;
            case 23:
               DoScriptText(SAY_DIA18, m_creature);
               JumpNextStep(9000);
               break;
            case 24:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
                   DoScriptText(SAY_DIA19, Leryssa);
               JumpNextStep(8000);
               break;
            case 25:
               DoScriptText(SAY_DIA20, m_creature);
               JumpNextStep(6000);
               break;
            case 26:
               m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
               JumpNextStep(60000);
               break;
            case 27:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
Kill(Leryssa);
               if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
                   Kill(Arlos);
               JumpNextStep(6000);
               EnterEvadeMode();
               m_creature->SetStandState(UNIT_STAND_STATE_STAND);
               break;
         }
    }

    void UpdateAI(const uint32 uiDiff)
    {
         if (m_uiStepTimer <= uiDiff)
             Event();
         else
             m_uiStepTimer -= uiDiff;

         if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

         DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_thassarian(Creature* pCreature)
{
    return new npc_thassarianAI(pCreature);
}

/*Prince Valanar AI*/

enum
{
   SPELL_SHADOW_BOLT = 15537,
   SPELL_SOUL_BLAST = 50992,
   SPELL_SOUL_MIRROR = 51009
};

struct MANGOS_DLL_DECL npc_valanarAI : public ScriptedAI
{
    npc_valanarAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        SetCombatMovement(false);
    }

    uint32 m_uiShadowBoltTimer;
    uint32 m_uiShadowBlastTimer;
    uint32 m_uiSoulTimer;

    void Reset()
    {
        m_uiShadowBoltTimer = 1300;
        m_uiShadowBlastTimer = 7300;
        m_uiSoulTimer = 17300;
    }
 
    void JustDied(Unit* pKiller)
    {
        if (Creature* pTas = GetClosestCreatureWithEntry(m_creature, NPC_THASSARIAN, 80.0f))
           ((npc_thassarianAI*)pTas->AI())->StartEvent(17);
    }

    void SpellHitTarget(Unit *target, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_SOUL_BLAST)
           m_creature->DealDamage(target, target->GetMaxHealth() / 5,NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (done_by->HasAura(SPELL_SOUL_MIRROR))
           m_creature->DealDamage(done_by, damage ,NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (m_uiShadowBoltTimer < diff)
        {
            if(Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0))
               DoCast(pTarget, SPELL_SHADOW_BOLT);
m_uiShadowBoltTimer = 3300;
        }
        else
            m_uiShadowBoltTimer -= diff;

        if (m_uiShadowBlastTimer < diff)
        {
           m_creature->InterruptNonMeleeSpells(false);
           if(Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0))
              DoCast(pTarget,SPELL_SOUL_BLAST);
m_uiShadowBlastTimer = urand(6000, 12000);
        }
        else
            m_uiShadowBlastTimer -= diff;

        if (m_uiSoulTimer < diff)
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature->getVictim(),SPELL_SOUL_MIRROR);
            m_uiSoulTimer = urand(15000, 20000);
        }
        else
            m_uiSoulTimer -= diff;
    }
};

bool GossipHello_npc_thassarian(Player *player, Creature *pCreature)
{
    if (pCreature->isQuestGiver())
        player->PrepareQuestMenu(pCreature->GetGUID());

    if (player->GetQuestStatus(QUEST_LAST_RITES) == QUEST_STATUS_INCOMPLETE)
        if(((npc_thassarianAI*)pCreature->AI())->m_uiStep == 0 && pCreature->GetAreaId() == AREA_ID)
            player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_T, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->PlayerTalkClass->SendGossipMenu(player->GetGossipTextId(pCreature),pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_thassarian(Player *player, Creature *pCreature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
          ((npc_thassarianAI*)pCreature->AI())->StartEvent(1);
          player->CLOSE_GOSSIP_MENU();
    }
    return true;
}

CreatureAI* GetAI_npc_valanar(Creature* pCreature)
{
    return new npc_valanarAI(pCreature);
}

/*######
## npc_mootoo_the_younger
######*/
enum Mootoo_the_Younger_Texts
{
    SAY_1                    = -1750040,
    SAY_2                    = -1750041,
    SAY_3                    = -1750042,
    SAY_4                    = -1750043,
    SAY_5                    = -1750044
};
enum Mootoo_the_Younger
{
    NPC_MOOTOO_THE_YOUNGER          =25504,
    QUEST_ESCAPING_THE_MIST         =11664
};


struct MANGOS_DLL_DECL npc_mootoo_the_youngerAI : public npc_escortAI
{
        npc_mootoo_the_youngerAI(Creature *pCreature) : npc_escortAI(pCreature) {}

        void Reset(){}

        void JustDied(Unit* /*killer*/)
        {
            if (Player* pPlayer=GetPlayerForEscort())
                pPlayer->FailQuest(QUEST_ESCAPING_THE_MIST);
        }

        void WaypointReached(uint32 uiPointId)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch(uiPointId)
            {
            case 10:
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                DoScriptText(SAY_2, m_creature);
                break;
            case 12:
                DoScriptText(SAY_3, m_creature);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                break;
            case 16:
                DoScriptText(SAY_4, m_creature);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                break;
            case 20:
                m_creature->SetPhaseMask(1,true);
                DoScriptText(SAY_5, m_creature);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                if (pPlayer)
                    pPlayer->GroupEventHappens(QUEST_ESCAPING_THE_MIST, m_creature);
                SetRun(true);
                break;
            }
        }
};

bool QuestAccept_npc_mootoo_the_younger(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ESCAPING_THE_MIST)
    {
        pCreature->SetStandState(UNIT_STAND_STATE_STAND);
        pCreature->setFaction((pPlayer->GetTeam() == ALLIANCE) ? FACTION_ESCORT_A_PASSIVE : FACTION_ESCORT_H_PASSIVE);
        DoScriptText(SAY_1, pCreature);

		if (npc_mootoo_the_youngerAI* pEscortAI = dynamic_cast<npc_mootoo_the_youngerAI*>(pCreature->AI()))
            	pEscortAI->Start(false, pPlayer, pQuest, true);

    }
    return true;
}

CreatureAI* GetAI_npc_mootoo_the_younger(Creature* pCreature)
{
    return new npc_mootoo_the_youngerAI(pCreature);
}

/*######
## npc_bonker_togglevolt
######*/

enum Bonker_Togglevolt
{
    NPC_BONKER_TOGGLEVOLT           = 25589,
    QUEST_GET_ME_OUTA_HERE          = 11673
};
enum Bonker_Togglevolt_Texts
{
	SAY_bonker_1					= -1700001,
    SAY_bonker_2                   	= -1700002,
    SAY_bonker_3                    = -1700003
	
};

struct MANGOS_DLL_DECL npc_bonker_togglevoltAI : public npc_escortAI
    {
        npc_bonker_togglevoltAI(Creature *pCreature) : npc_escortAI(pCreature) {}
        
        void Reset(){}

        void JustDied(Unit* /*killer*/)
        {
            if (Player* pPlayer = GetPlayerForEscort())
                pPlayer->FailQuest(QUEST_ESCAPING_THE_MIST);
        }

        void WaypointReached(uint32 uiPointId)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch(uiPointId)
            {
			case 1:
				DoScriptText(SAY_bonker_1,m_creature);
				break;
			case 3:
				DoScriptText(SAY_bonker_2,m_creature);
				break;
            case 29:
				DoScriptText(SAY_bonker_3,m_creature);
                if (pPlayer)
                    pPlayer->GroupEventHappens(QUEST_GET_ME_OUTA_HERE, m_creature);
                break;
            }
        }
    };

    

bool QuestAccept_npc_bonker_togglevolt(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_GET_ME_OUTA_HERE)
        {
            pCreature->SetStandState(UNIT_STAND_STATE_STAND);
	        pCreature->setFaction((pPlayer->GetTeam() == ALLIANCE) ? FACTION_ESCORT_A_PASSIVE : FACTION_ESCORT_H_PASSIVE);            
	        DoScriptText(SAY_bonker_2, pCreature, pPlayer);
            
			if (npc_bonker_togglevoltAI* pEscortAI = dynamic_cast<npc_bonker_togglevoltAI*>(pCreature->AI()))
            		pEscortAI->Start(false, pPlayer, pQuest, true);
        }
        return true;
    }

CreatureAI* GetAI_npc_bonker_togglevolt(Creature* pCreature)
{
    return new npc_bonker_togglevoltAI(pCreature);
}

/*######
## Quest 11608: Bury Those Cockroaches!
######*/
enum
{
    QUEST_BURY_THOSE_COCKROACHES            = 11608,
    SPELL_SEAFORIUM_DEPTH_CHARGE_EXPLOSION  = 45502


};
struct npc_seaforium_depth_chargeAI : public ScriptedAI
{
    npc_seaforium_depth_chargeAI(Creature *pCreature) : ScriptedAI(pCreature) {}

    uint32 uiExplosionTimer;
    void Reset()
    {
        uiExplosionTimer = urand(5000,10000);
    }
    void UpdateAI(const uint32 diff)
    {
        if (uiExplosionTimer < diff)
        {
            DoCast(m_creature, SPELL_SEAFORIUM_DEPTH_CHARGE_EXPLOSION);          
            for(uint8 i = 0; i < 4; ++i)
            {
                if(Creature* cCredit = GetClosestCreatureWithEntry(m_creature, 25402 + i, 10.0f))//25402-25405 credit markers
                {
                    if(Player *pPlayer = m_creature->GetMap()->GetPlayer(m_creature->GetCreatorGuid()))
                    {
                        if(pPlayer->GetQuestStatus(QUEST_BURY_THOSE_COCKROACHES) == QUEST_STATUS_INCOMPLETE)
                            pPlayer->KilledMonsterCredit(cCredit->GetEntry(),cCredit->GetGUID());
                    }                    
                }
            }
            m_creature->ForcedDespawn(1000);
        } else uiExplosionTimer -= diff;
    }
};

CreatureAI* GetAI_npc_seaforium_depth_charge(Creature* pCreature)
{
    return new npc_seaforium_depth_chargeAI(pCreature);
}

void AddSC_borean_tundra()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "npc_fizzcrank_fullthrottle";
    pNewScript->pGossipHello = &GossipHello_npc_fizzcrank_fullthrottle;
    pNewScript->pGossipSelect = &GossipSelect_npc_fizzcrank_fullthrottle;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_iruk";
    pNewScript->pGossipHello = &GossipHello_npc_iruk;
    pNewScript->pGossipSelect = &GossipSelect_npc_iruk;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_kara_thricestar";
    pNewScript->pGossipHello = &GossipHello_npc_kara_thricestar;
    pNewScript->pGossipSelect = &GossipSelect_npc_kara_thricestar;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_nesingwary_trapper";
    pNewScript->GetAI = &GetAI_npc_nesingwary_trapper;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_oil_stained_wolf";
    pNewScript->GetAI = &GetAI_npc_oil_stained_wolf;
    pNewScript->pEffectDummyNPC = &EffectDummyCreature_npc_oil_stained_wolf;
    pNewScript->pEffectAuraDummy = &EffectAuraDummy_npc_oil_stained_wolf;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_caribou_trap";
    pNewScript->pGOUse = &GOUse_go_caribou_trap;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_sinkhole_kill_credit";
    pNewScript->GetAI = &GetAI_npc_sinkhole_kill_credit;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_surristrasz";
    pNewScript->pGossipHello = &GossipHello_npc_surristrasz;
    pNewScript->pGossipSelect = &GossipSelect_npc_surristrasz;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_tiare";
    pNewScript->pGossipHello = &GossipHello_npc_tiare;
    pNewScript->pGossipSelect = &GossipSelect_npc_tiare;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_lurgglbr";
    pNewScript->GetAI = &GetAI_npc_lurgglbr;
    pNewScript->pQuestAcceptNPC = &QuestAccept_npc_lurgglbr;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_valanar";
    pNewScript->GetAI = &GetAI_npc_valanar;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_thassarian";
    pNewScript->GetAI = &GetAI_npc_thassarian;
    pNewScript->pGossipHello = &GossipHello_npc_thassarian;
    pNewScript->pGossipSelect = &GossipSelect_npc_thassarian;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_mootoo_the_younger";
    pNewScript->GetAI = &GetAI_npc_mootoo_the_younger;
    pNewScript->pQuestAcceptNPC = &QuestAccept_npc_mootoo_the_younger;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_bonker_togglevolt";
    pNewScript->GetAI = &GetAI_npc_bonker_togglevolt;
    pNewScript->pQuestAcceptNPC = &QuestAccept_npc_bonker_togglevolt;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_seaforium_depth_charge";
    pNewScript->GetAI = &GetAI_npc_seaforium_depth_charge;
    pNewScript->RegisterSelf();
}

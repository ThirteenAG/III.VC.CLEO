#include "CustomOpcodes.h"
#include "Game.h"
#include "OpcodesSystem.h"
#include "ScriptManager.h"
#include "Log.h"
#include "Fxt.h"
#include "CleoVersion.h"
#include <direct.h>
int format(CScript *script, char *str, size_t len, const char *format);

CLEOAPI tScriptVar* CLEO_GetParamsAddress()
{
	return game.Scripts.Params;
}

CLEOAPI char* CLEO_GetScriptSpaceAddress()
{
	return game.Scripts.Space;
}

CLEOAPI unsigned CLEO_GetVersion()
{
	return CLEO_VERSION;
}

void CustomOpcodes::Register()
{
	Opcodes::RegisterOpcode(0x0002, GOTO);
	Opcodes::RegisterOpcode(0x004C, GOTO_IF_TRUE);
	Opcodes::RegisterOpcode(0x004D, GOTO_IF_FALSE);
	Opcodes::RegisterOpcode(0x0050, GOSUB);
	Opcodes::RegisterOpcode(0x05DC, TERMINATE_CUSTOM_THREAD);
	Opcodes::RegisterOpcode(0x05DD, TERMINATE_NAMED_CUSTOM_THREAD);
	Opcodes::RegisterOpcode(0x05DE, START_CUSTOM_THREAD);
	Opcodes::RegisterOpcode(0x05DF, MEMORY_WRITE);
	Opcodes::RegisterOpcode(0x05E0, MEMORY_READ);
	Opcodes::RegisterOpcode(0x05E1, CALL);
	Opcodes::RegisterOpcode(0x05E2, CALL_FUNCTION);
	Opcodes::RegisterOpcode(0x05E3, CALL_METHOD);
	Opcodes::RegisterOpcode(0x05E4, CALL_FUNCTION_METHOD);
	Opcodes::RegisterOpcode(0x05E5, GET_GAME_VERSION);
	Opcodes::RegisterOpcode(0x05E6, GET_CHAR_STRUCT);
	Opcodes::RegisterOpcode(0x05E7, GET_CAR_STRUCT);
	Opcodes::RegisterOpcode(0x05E8, GET_OBJECT_STRUCT);
	Opcodes::RegisterOpcode(0x05E9, GET_CHAR_HANDLE);
	Opcodes::RegisterOpcode(0x05EA, GET_CAR_HANDLE);
	Opcodes::RegisterOpcode(0x05EB, GET_OBJECT_HANDLE);
	Opcodes::RegisterOpcode(0x05EC, GET_THREAD_POINTER);
	Opcodes::RegisterOpcode(0x05ED, GET_NAMED_THREAD_POINTER);
	Opcodes::RegisterOpcode(0x05EE, IS_KEY_PRESSED);
	Opcodes::RegisterOpcode(0x05EF, FIND_RANDOM_CHAR);
	Opcodes::RegisterOpcode(0x05F0, FIND_RANDOM_CAR);
	Opcodes::RegisterOpcode(0x05F1, FIND_RANDOM_OBJECT);
	Opcodes::RegisterOpcode(0x05F2, CALL_POP_FLOAT);
	Opcodes::RegisterOpcode(0x05F3, MATH_EXP);
	Opcodes::RegisterOpcode(0x05F4, MATH_LOG);
	Opcodes::RegisterOpcode(0x05F5, CALL_SCM_FUNCTION);
	Opcodes::RegisterOpcode(0x05F6, SCM_FUNCTION_RET);
	Opcodes::RegisterOpcode(0x05F7, GET_LABEL_OFFSET);
	Opcodes::RegisterOpcode(0x05F8, GET_VAR_OFFSET);
	Opcodes::RegisterOpcode(0x05F9, BIT_AND);
	Opcodes::RegisterOpcode(0x05FA, BIT_OR);
	Opcodes::RegisterOpcode(0x05FB, BIT_XOR);
	Opcodes::RegisterOpcode(0x05FC, BIT_NOT);
	Opcodes::RegisterOpcode(0x05FD, BIT_MOD);
	Opcodes::RegisterOpcode(0x05FE, BIT_SHR);
	Opcodes::RegisterOpcode(0x05FF, BIT_SHL);

	//CLEO4 SA opcodes including duplicates with new ids
	Opcodes::RegisterOpcode(0x0A8C, MEMORY_WRITE);
	Opcodes::RegisterOpcode(0x0A8D, MEMORY_READ);
	Opcodes::RegisterOpcode(0x0A8E, OPCODE_0A8E);
	Opcodes::RegisterOpcode(0x0A8F, OPCODE_0A8F);
	Opcodes::RegisterOpcode(0x0A90, OPCODE_0A90);
	Opcodes::RegisterOpcode(0x0A91, OPCODE_0A91);
	Opcodes::RegisterOpcode(0x0A92, START_CUSTOM_THREAD_VSTRING);
	Opcodes::RegisterOpcode(0x0A93, TERMINATE_CUSTOM_THREAD);
	Opcodes::RegisterOpcode(0x0A94, DUMMY);
	Opcodes::RegisterOpcode(0x0A95, DUMMY);
	Opcodes::RegisterOpcode(0x0A96, GET_CHAR_STRUCT);
	Opcodes::RegisterOpcode(0x0A97, GET_CAR_STRUCT);
	Opcodes::RegisterOpcode(0x0A98, GET_OBJECT_STRUCT);
	Opcodes::RegisterOpcode(0x0A99, OPCODE_0A99);
	Opcodes::RegisterOpcode(0x0A9A, OPCODE_0A9A);
	Opcodes::RegisterOpcode(0x0A9B, OPCODE_0A9B);
	Opcodes::RegisterOpcode(0x0A9C, OPCODE_0A9C);
	Opcodes::RegisterOpcode(0x0A9D, OPCODE_0A9D);
	Opcodes::RegisterOpcode(0x0A9E, OPCODE_0A9E);
	Opcodes::RegisterOpcode(0x0A9F, GET_THREAD_POINTER);
	Opcodes::RegisterOpcode(0x0AA0, OPCODE_0AA0);
	Opcodes::RegisterOpcode(0x0AA1, OPCODE_0AA1);
	Opcodes::RegisterOpcode(0x0AA2, OPCODE_0AA2);
	Opcodes::RegisterOpcode(0x0AA3, OPCODE_0AA3);
	Opcodes::RegisterOpcode(0x0AA4, OPCODE_0AA4);
	Opcodes::RegisterOpcode(0x0AA5, CALL);
	Opcodes::RegisterOpcode(0x0AA6, CALL_METHOD);
	Opcodes::RegisterOpcode(0x0AA7, CALL_FUNCTION);
	Opcodes::RegisterOpcode(0x0AA8, CALL_FUNCTION_METHOD);
	Opcodes::RegisterOpcode(0x0AA9, OPCODE_0AA9);
	Opcodes::RegisterOpcode(0x0AAA, GET_NAMED_THREAD_POINTER);
	Opcodes::RegisterOpcode(0x0AAB, OPCODE_0AAB);
	Opcodes::RegisterOpcode(0x0AAC, DUMMY);
	Opcodes::RegisterOpcode(0x0AAD, DUMMY);
	Opcodes::RegisterOpcode(0x0AAE, DUMMY);
	Opcodes::RegisterOpcode(0x0AAF, DUMMY);
	Opcodes::RegisterOpcode(0x0AB0, IS_KEY_PRESSED);
	Opcodes::RegisterOpcode(0x0AB1, CALL_SCM_FUNCTION);
	Opcodes::RegisterOpcode(0x0AB2, SCM_FUNCTION_RET);
	Opcodes::RegisterOpcode(0x0AB3, DUMMY);
	Opcodes::RegisterOpcode(0x0AB4, DUMMY);
	Opcodes::RegisterOpcode(0x0AB5, DUMMY);
	Opcodes::RegisterOpcode(0x0AB6, DUMMY);
	Opcodes::RegisterOpcode(0x0AB7, DUMMY);
	Opcodes::RegisterOpcode(0x0AB8, DUMMY);
	Opcodes::RegisterOpcode(0x0AB9, DUMMY);
	Opcodes::RegisterOpcode(0x0ABA, TERMINATE_NAMED_CUSTOM_THREAD);
	Opcodes::RegisterOpcode(0x0ABB, DUMMY);
	Opcodes::RegisterOpcode(0x0ABC, DUMMY);
	Opcodes::RegisterOpcode(0x0ABD, DUMMY);
	Opcodes::RegisterOpcode(0x0ABE, DUMMY);
	Opcodes::RegisterOpcode(0x0ABF, DUMMY);
	Opcodes::RegisterOpcode(0x0AC0, DUMMY);
	Opcodes::RegisterOpcode(0x0AC1, DUMMY);
	Opcodes::RegisterOpcode(0x0AC2, DUMMY);
	Opcodes::RegisterOpcode(0x0AC3, DUMMY);
	Opcodes::RegisterOpcode(0x0AC4, DUMMY);
	Opcodes::RegisterOpcode(0x0AC5, DUMMY);
	Opcodes::RegisterOpcode(0x0AC6, GET_LABEL_OFFSET);
	Opcodes::RegisterOpcode(0x0AC7, GET_VAR_OFFSET);
	Opcodes::RegisterOpcode(0x0AC8, OPCODE_0AC8);
	Opcodes::RegisterOpcode(0x0AC9, OPCODE_0AC9);
	Opcodes::RegisterOpcode(0x0ACA, OPCODE_0ACA);
	Opcodes::RegisterOpcode(0x0ACB, OPCODE_0ACB);
	Opcodes::RegisterOpcode(0x0ACC, OPCODE_0ACC);
	Opcodes::RegisterOpcode(0x0ACD, OPCODE_0ACD);
	Opcodes::RegisterOpcode(0x0ACE, OPCODE_0ACE);
	Opcodes::RegisterOpcode(0x0ACF, OPCODE_0ACF);
	Opcodes::RegisterOpcode(0x0AD0, OPCODE_0AD0);
	Opcodes::RegisterOpcode(0x0AD1, OPCODE_0AD1);
	Opcodes::RegisterOpcode(0x0AD2, DUMMY);
	Opcodes::RegisterOpcode(0x0AD3, OPCODE_0AD3);
	Opcodes::RegisterOpcode(0x0AD4, OPCODE_0AD4);
	Opcodes::RegisterOpcode(0x0AD5, OPCODE_0AD5);
	Opcodes::RegisterOpcode(0x0AD6, OPCODE_0AD6);
	Opcodes::RegisterOpcode(0x0AD7, OPCODE_0AD7);
	Opcodes::RegisterOpcode(0x0AD8, OPCODE_0AD8);
	Opcodes::RegisterOpcode(0x0AD9, OPCODE_0AD9);
	Opcodes::RegisterOpcode(0x0ADA, OPCODE_0ADA);
	Opcodes::RegisterOpcode(0x0ADB, OPCODE_0ADB);
	Opcodes::RegisterOpcode(0x0ADC, OPCODE_0ADC);
	Opcodes::RegisterOpcode(0x0ADD, OPCODE_0ADD);
	Opcodes::RegisterOpcode(0x0ADE, OPCODE_0ADE);
	Opcodes::RegisterOpcode(0x0ADF, OPCODE_0ADF);
	Opcodes::RegisterOpcode(0x0AE0, OPCODE_0AE0);
	Opcodes::RegisterOpcode(0x0AE1, FIND_RANDOM_CHAR);
	Opcodes::RegisterOpcode(0x0AE2, FIND_RANDOM_CAR);
	Opcodes::RegisterOpcode(0x0AE3, FIND_RANDOM_OBJECT);
	Opcodes::RegisterOpcode(0x0AE4, DUMMY);
	Opcodes::RegisterOpcode(0x0AE5, DUMMY);
	Opcodes::RegisterOpcode(0x0AE6, DUMMY);
	Opcodes::RegisterOpcode(0x0AE7, DUMMY);
	Opcodes::RegisterOpcode(0x0AE8, DUMMY);
	Opcodes::RegisterOpcode(0x0AE9, CALL_POP_FLOAT);
	Opcodes::RegisterOpcode(0x0AEA, GET_CHAR_HANDLE);
	Opcodes::RegisterOpcode(0x0AEB, GET_CAR_HANDLE);
	Opcodes::RegisterOpcode(0x0AEC, GET_OBJECT_HANDLE);
	Opcodes::RegisterOpcode(0x0AED, DUMMY);
	Opcodes::RegisterOpcode(0x0AEE, MATH_EXP);
	Opcodes::RegisterOpcode(0x0AEF, MATH_LOG);

	//CLEO 2 opcodes
	Opcodes::RegisterOpcode(0x0600, START_CUSTOM_THREAD_VSTRING);
	Opcodes::RegisterOpcode(0x0601, IS_BUTTON_PRESSED_ON_PAD);
	Opcodes::RegisterOpcode(0x0602, EMULATE_BUTTON_PRESS_ON_PAD);
	Opcodes::RegisterOpcode(0x0603, IS_CAMERA_IN_WIDESCREEN_MODE);
	Opcodes::RegisterOpcode(0x0604, GET_MODEL_ID_FROM_WEAPON_ID);
	Opcodes::RegisterOpcode(0x0605, GET_WEAPON_ID_FROM_MODEL_ID);
	Opcodes::RegisterOpcode(0x0606, SET_MEM_OFFSET);
	Opcodes::RegisterOpcode(0x0607, GET_CURRENT_WEATHER);
	Opcodes::RegisterOpcode(0x0608, SHOW_TEXT_POSITION);
	Opcodes::RegisterOpcode(0x0609, SHOW_FORMATTED_TEXT_POSITION);

	//Original opcodes added since VC
	Opcodes::RegisterOpcode(0x04C2, STORE_COORDS_FROM_OBJECT_WITH_OFFSET); //0400
	Opcodes::RegisterOpcode(0x04C3, STORE_COORDS_FROM_CAR_WITH_OFFSET); //0407
	Opcodes::RegisterOpcode(0x04C4, STORE_COORDS_FROM_ACTOR_WITH_OFFSET);

	Opcodes::RegisterOpcode(0x046F, STORE_PLAYER_CURRENTLY_ARMED_WEAPON);
}

eOpcodeResult CustomOpcodes::DUMMY(CScript *script)
{
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GOTO(CScript *script)
{
	script->Collect(1);
	script->JumpTo(game.Scripts.Params[0].nVar);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GOTO_IF_TRUE(CScript *script)
{
	script->Collect(1);
	if(script->m_bCondResult)
		script->JumpTo(game.Scripts.Params[0].nVar);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GOTO_IF_FALSE(CScript *script)
{
	script->Collect(1);
	if(!script->m_bCondResult)
		script->JumpTo(game.Scripts.Params[0].nVar);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GOSUB(CScript *script)
{
	script->Collect(1);
	script->m_aGosubAddr[script->m_nCurrentGosub++] = script->m_dwIp;
	script->JumpTo(game.Scripts.Params[0].nVar);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::TERMINATE_CUSTOM_THREAD(CScript *script)
{
	game.Scripts.RemoveScriptFromList(script, game.Scripts.pActiveScriptsList);
	script->RemoveFromCustomList(&scriptMgr.pCusomScripts);
	scriptMgr.numLoadedCustomScripts--;
	LOGL(LOG_PRIORITY_OPCODE, "TERMINATE_CUSTOM_THREAD: Terminating custom script \"%s\"", script->m_acName);
	delete script;
	return OR_TERMINATE;
}

eOpcodeResult CustomOpcodes::TERMINATE_NAMED_CUSTOM_THREAD(CScript *script)
{
	char name[8];
	script->ReadShortString(name);
	CScript *search = scriptMgr.pCusomScripts;
	eOpcodeResult result = OR_CONTINUE;
	bool found = false;
	while(search)
	{
		CScript *next = search->m_pNextCustom;
		if(!stricmp(search->m_acName, name))
		{
			if(search == script)
				result = OR_TERMINATE;
			game.Scripts.RemoveScriptFromList(search, game.Scripts.pActiveScriptsList);
			search->RemoveFromCustomList(&scriptMgr.pCusomScripts);
			scriptMgr.numLoadedCustomScripts--;
			LOGL(LOG_PRIORITY_OPCODE, "TERMINATE_NAMED_CUSTOM_THREAD: Terminating custom script with name \"%s\"", search->m_acName);
			delete search;
			found = true;
		}
		search = next;
	}
	if(found)
		script->UpdateCompareFlag(true);
	else
		script->UpdateCompareFlag(false);
	return result;
}

eOpcodeResult CustomOpcodes::START_CUSTOM_THREAD(CScript *script)
{
	char name[8];
	script->ReadShortString(name);
	char filepath[MAX_PATH];
	sprintf(filepath, "%s%.8s", "cleo\\", name);
	CScript *newScript = new CScript(filepath);
	if(newScript && newScript->Loaded())
	{
		newScript->AddToCustomList(&scriptMgr.pCusomScripts);
		scriptMgr.numLoadedCustomScripts++;
		game.Scripts.AddScriptToList(newScript, game.Scripts.pActiveScriptsList);
		newScript->m_bIsActive = true;
		LOGL(LOG_PRIORITY_OPCODE, "START_CUSTOM_THREAD: Started new script \"%s\"", name);
		for(int i = 0; (*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type; i++)
		{
			script->Collect(1);
			newScript->m_aLVars[i].nVar = game.Scripts.Params[0].nVar;
		}
		script->UpdateCompareFlag(true);
	}
	else
	{
		while((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
			script->Collect(1);
		LOGL(LOG_PRIORITY_OPCODE, "START_CUSTOM_THREAD: Script loading failed, \"%s\"", name);
		if(newScript)
			delete newScript;
		script->UpdateCompareFlag(false);
	}
	script->m_dwIp++;
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::MEMORY_WRITE(CScript *script)
{
	script->Collect(4);
	DWORD flOldProtect;
	if(game.Scripts.Params[3].nVar)
		VirtualProtect(game.Scripts.Params[0].pVar, game.Scripts.Params[1].nVar, PAGE_EXECUTE_READWRITE, &flOldProtect);
	switch(game.Scripts.Params[1].nVar)
	{
	case 1:
		*(char *)game.Scripts.Params[0].pVar = game.Scripts.Params[2].nVar;
		break;
	case 2:
		*(short *)game.Scripts.Params[0].pVar = game.Scripts.Params[2].nVar;
		break;
	case 4:
		*(int *)game.Scripts.Params[0].pVar = game.Scripts.Params[2].nVar;
		break;
	default:
		memset(game.Scripts.Params[0].pVar, game.Scripts.Params[2].nVar, game.Scripts.Params[1].nVar);
		break;
	}
	if(game.Scripts.Params[3].nVar)
		VirtualProtect(game.Scripts.Params[0].pVar, game.Scripts.Params[1].nVar, flOldProtect, &flOldProtect);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::MEMORY_READ(CScript *script)
{
	script->Collect(3);
	DWORD flOldProtect;
	void *pMemory = game.Scripts.Params[0].pVar;
	if(game.Scripts.Params[2].nVar)
		VirtualProtect(pMemory, game.Scripts.Params[1].nVar, PAGE_EXECUTE_READWRITE, &flOldProtect);
	switch(game.Scripts.Params[1].nVar)
	{
	case 1:
		game.Scripts.Params[0].nVar = *(unsigned char *)pMemory;
		break;
	case 2:
		game.Scripts.Params[0].nVar = *(unsigned short *)pMemory;
		break;
	case 4:
		game.Scripts.Params[0].nVar = *(int *)pMemory;
		break;
	default:
		game.Scripts.Params[0].nVar = 0;
		break;
	}
	if(game.Scripts.Params[2].nVar)
		VirtualProtect(pMemory, game.Scripts.Params[1].nVar, flOldProtect, &flOldProtect);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::CALL(CScript *script)
{
	script->Collect(3);
	void *func = game.Scripts.Params[0].pVar;
	unsigned int popsize = game.Scripts.Params[2].nVar * 4;
	for(int i = 0; i < game.Scripts.Params[1].nVar; i++)
	{
		script->Collect(1);
		unsigned int param = game.Scripts.Params[0].nVar;
		__asm push param
	}
	__asm call func
	__asm add esp, popsize
	while((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::CALL_FUNCTION(CScript *script)
{
	script->Collect(3);
	void *func = game.Scripts.Params[0].pVar;
	int func_result;
	unsigned int popsize = game.Scripts.Params[2].nVar * 4;
	for(int i = 0; i < game.Scripts.Params[1].nVar; i++)
	{
		script->Collect(1);
		unsigned int param = game.Scripts.Params[0].nVar;
		__asm push param
	}
	__asm call func
	__asm mov func_result, eax
	__asm add esp, popsize
	game.Scripts.Params[0].nVar = func_result;
	script->Store(1);
	while((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::CALL_METHOD(CScript *script)
{
	script->Collect(4);
	void *func = game.Scripts.Params[0].pVar;
	void *object = game.Scripts.Params[1].pVar;
	unsigned int popsize = game.Scripts.Params[3].nVar * 4;
	for(int i = 0; i < game.Scripts.Params[2].nVar; i++)
	{
		script->Collect(1);
		unsigned int param = game.Scripts.Params[0].nVar;
		__asm push param
	}
	__asm mov ecx, object
	__asm call func
	__asm add esp, popsize
	while((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::CALL_FUNCTION_METHOD(CScript *script)
{
	script->Collect(4);
	void *func = game.Scripts.Params[0].pVar;
	void *object = game.Scripts.Params[1].pVar;
	int func_result;
	unsigned int popsize = game.Scripts.Params[3].nVar * 4;
	for(int i = 0; i < game.Scripts.Params[2].nVar; i++)
	{
		script->Collect(1);
		unsigned int param = game.Scripts.Params[0].nVar;
		__asm push param
	}
	__asm mov ecx, object
	__asm call func
	__asm mov func_result, eax
	__asm add esp, popsize
	game.Scripts.Params[0].nVar = func_result;
	script->Store(1);
	while((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_GAME_VERSION(CScript *script)
{
	game.Scripts.Params[0].nVar = game.Version - 1;
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_CHAR_STRUCT(CScript *script)
{
	script->Collect(1);
	game.Scripts.Params[0].pVar = game.Pools.pfPedPoolGetStruct(*game.Pools.pPedPool, game.Scripts.Params[0].nVar);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_CAR_STRUCT(CScript *script)
{
	script->Collect(1);
	game.Scripts.Params[0].pVar = game.Pools.pfVehiclePoolGetStruct(*game.Pools.pVehiclePool, game.Scripts.Params[0].nVar);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_OBJECT_STRUCT(CScript *script)
{
	script->Collect(1);
	game.Scripts.Params[0].pVar = game.Pools.pfObjectPoolGetStruct(*game.Pools.pObjectPool, game.Scripts.Params[0].nVar);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_CHAR_HANDLE(CScript *script)
{
	script->Collect(1);
	game.Scripts.Params[0].nVar = game.Pools.pfPedPoolGetHandle(*game.Pools.pPedPool, game.Scripts.Params[0].pVar);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_CAR_HANDLE(CScript *script)
{
	script->Collect(1);
	game.Scripts.Params[0].nVar = game.Pools.pfVehiclePoolGetHandle(*game.Pools.pVehiclePool, game.Scripts.Params[0].pVar);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_OBJECT_HANDLE(CScript *script)
{
	script->Collect(1);
	game.Scripts.Params[0].nVar = game.Pools.pfObjectPoolGetHandle(*game.Pools.pObjectPool, game.Scripts.Params[0].pVar);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_THREAD_POINTER(CScript *script)
{
	game.Scripts.Params[0].pVar = script;
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_NAMED_THREAD_POINTER(CScript *script)
{
	char name[8];
	script->ReadShortString(name);
	CScript *result_ptr = 0;
	CScript *search = scriptMgr.pCusomScripts;
	while(search)
	{
		if(!stricmp(search->m_acName, name))
		{
			result_ptr = search;
			break;
		}
		search = search->m_pNextCustom;
	}
	if(!result_ptr)
	{
		for(int i = 0; i < 128; i++)
		{
			if(!stricmp(scriptMgr.gameScripts[i].m_acName, name))
			{
				result_ptr = &scriptMgr.gameScripts[i];
				break;
			}
		}
	}
	game.Scripts.Params[0].pVar = result_ptr;
	if(result_ptr)
		script->UpdateCompareFlag(true);
	else
		script->UpdateCompareFlag(false);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::IS_KEY_PRESSED(CScript *script)
{
	script->Collect(1);
	script->UpdateCompareFlag(GetKeyState(game.Scripts.Params[0].nVar) & 0x8000);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::FIND_RANDOM_CHAR(CScript *script)
{
	script->Collect(6);
	unsigned int objcount;
	if(game.Scripts.Params[4].nVar)
	{
		if(!script->m_nLastPedSearchIndex)
		{
			game.Scripts.Params[0].nVar = 0;
			script->Store(1);
			script->UpdateCompareFlag(false);
			return OR_CONTINUE;
		}
		objcount = script->m_nLastPedSearchIndex;
	}
	else
	{
		if(!(*game.Pools.pPedPool)->capacity)
		{
			game.Scripts.Params[0].nVar = 0;
			script->Store(1);
			script->UpdateCompareFlag(false);
			return OR_CONTINUE;
		}
		objcount = (*game.Pools.pPedPool)->capacity;
	}
	unsigned int poolobj = (unsigned int)(*game.Pools.pPedPool)->objects + objcount * 0x5F0;
	bool found = 0;
	float maxsq = game.Scripts.Params[3].fVar * game.Scripts.Params[3].fVar;
	for(int i = objcount - 1; i >= 0; i--)
	{
		poolobj -= 0x5F0;
		if(!((*game.Pools.pPedPool)->flags[i] & 0x80))
		{
			if(*(unsigned int *)(poolobj + 0x32C))
			{
				if(!game.Scripts.Params[5].nVar || (*(unsigned int *)(poolobj + 0x224) != 48 && *(unsigned int *)(poolobj + 0x224) != 49))
				{
					float xd = *(float *)(poolobj + 0x34) - game.Scripts.Params[0].fVar;
					float yd = *(float *)(poolobj + 0x38) - game.Scripts.Params[1].fVar;
					float zd = *(float *)(poolobj + 0x3C) - game.Scripts.Params[2].fVar;
					float distsq = xd * xd + yd * yd + zd * zd;
					if(distsq <= maxsq)
					{
						found = true;
						script->m_nLastPedSearchIndex = i;
						game.Scripts.Params[0].nVar = game.Pools.pfPedPoolGetHandle(*game.Pools.pPedPool, (void *)poolobj);
						script->UpdateCompareFlag(true);
						break;
					}
				}
			}
		}
	}
	if(!found)
	{
		game.Scripts.Params[0].nVar = -1;
		script->UpdateCompareFlag(false);
		script->m_nLastPedSearchIndex = 0;
	}
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::FIND_RANDOM_CAR(CScript *script)
{
	script->Collect(6);
	unsigned int objcount;
	if(game.Scripts.Params[4].nVar)
	{
		if(!script->m_nLastVehicleSearchIndex)
		{
			game.Scripts.Params[0].nVar = 0;
			script->Store(1);
			script->UpdateCompareFlag(false);
			return OR_CONTINUE;
		}
		objcount = script->m_nLastVehicleSearchIndex;
	}
	else
	{
		if(!(*game.Pools.pVehiclePool)->capacity)
		{
			game.Scripts.Params[0].nVar = 0;
			script->Store(1);
			script->UpdateCompareFlag(false);
			return OR_CONTINUE;
		}
		objcount = (*game.Pools.pVehiclePool)->capacity;
	}
	unsigned int poolobj = (unsigned int)(*game.Pools.pVehiclePool)->objects + objcount * 0x5A8;
	bool found = 0;
	float maxsq = game.Scripts.Params[3].fVar * game.Scripts.Params[3].fVar;
	for(int i = objcount - 1; i >= 0; i--)
	{
		poolobj -= 0x5A8;
		if(!((*game.Pools.pVehiclePool)->flags[i] & 0x80))
		{
			if(!game.Scripts.Params[5].nVar || ((*(unsigned char *)(poolobj + 0x50) & 0xF8) != 40 && *(unsigned int *)(poolobj + 0x284) != 1 && !(*(unsigned char *)(poolobj + 0x122) & 8)))
			{
				float xd = *(float *)(poolobj + 0x34) - game.Scripts.Params[0].fVar;
				float yd = *(float *)(poolobj + 0x38) - game.Scripts.Params[1].fVar;
				float zd = *(float *)(poolobj + 0x3C) - game.Scripts.Params[2].fVar;
				float distsq = xd * xd + yd * yd + zd * zd;
				if(distsq <= maxsq)
				{
					found = true;
					script->m_nLastVehicleSearchIndex = i;
					game.Scripts.Params[0].nVar = game.Pools.pfVehiclePoolGetHandle(*game.Pools.pVehiclePool, (void *)poolobj);
					script->UpdateCompareFlag(true);
					break;
				}
			}
		}
	}
	if(!found)
	{
		game.Scripts.Params[0].nVar = -1;
		script->UpdateCompareFlag(false);
		script->m_nLastVehicleSearchIndex = 0;
	}
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::FIND_RANDOM_OBJECT(CScript *script)
{
	script->Collect(5);
	unsigned int objcount;
	if(game.Scripts.Params[4].nVar)
	{
		if(!script->m_nLastObjectSearchIndex)
		{
			game.Scripts.Params[0].nVar = 0;
			script->Store(1);
			script->UpdateCompareFlag(false);
			return OR_CONTINUE;
		}
		objcount = script->m_nLastObjectSearchIndex;
	}
	else
	{
		if(!(*game.Pools.pObjectPool)->capacity)
		{
			game.Scripts.Params[0].nVar = 0;
			script->Store(1);
			script->UpdateCompareFlag(false);
			return OR_CONTINUE;
		}
		objcount = (*game.Pools.pObjectPool)->capacity;
	}
	unsigned int poolobj = (unsigned int)(*game.Pools.pObjectPool)->objects + objcount * 0x19C;
	bool found = 0;
	float maxsq = game.Scripts.Params[3].fVar * game.Scripts.Params[3].fVar;
	for(int i = objcount - 1; i >= 0; i--)
	{
		poolobj -= 0x19C;
		if(!((*game.Pools.pObjectPool)->flags[i] & 0x80))
		{
			float xd = *(float *)(poolobj + 0x34) - game.Scripts.Params[0].fVar;
			float yd = *(float *)(poolobj + 0x38) - game.Scripts.Params[1].fVar;
			float zd = *(float *)(poolobj + 0x3C) - game.Scripts.Params[2].fVar;
			float distsq = xd * xd + yd * yd + zd * zd;
			if(distsq <= maxsq)
			{
				found = true;
				script->m_nLastObjectSearchIndex = i;
				game.Scripts.Params[0].nVar = game.Pools.pfObjectPoolGetHandle(*game.Pools.pObjectPool, (void *)poolobj);
				script->UpdateCompareFlag(true);
				break;
			}
		}
	}
	if(!found)
	{
		game.Scripts.Params[0].nVar = -1;
		script->UpdateCompareFlag(false);
		script->m_nLastObjectSearchIndex = 0;
	}
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::CALL_POP_FLOAT(CScript *script)
{
	float *pParam = &game.Scripts.Params[0].fVar;
	__asm mov eax, pParam
	__asm fstp [eax]
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::MATH_EXP(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].fVar = powf(game.Scripts.Params[0].fVar, game.Scripts.Params[1].fVar);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::MATH_LOG(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].fVar =  logf(game.Scripts.Params[0].fVar) / logf(game.Scripts.Params[1].fVar);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::CALL_SCM_FUNCTION(CScript *script)
{
	script->m_pScmFunction = new ScmFunction(script);
	script->Collect(2);
	int addr = game.Scripts.Params[0].nVar;
	unsigned int paramCount = game.Scripts.Params[1].nVar;
	if(paramCount > 0)
		script->Collect(paramCount);
	memset(script->m_aLVars, 0, 64);
	if(paramCount > 0)
		memcpy(script->m_aLVars, game.Scripts.Params, paramCount * 4);
	script->m_pScmFunction->retAddr = script->m_dwIp;
	script->JumpTo(addr);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::SCM_FUNCTION_RET(CScript *script)
{
	script->Collect(1);
	unsigned int paramCount = game.Scripts.Params[0].nVar;
	if(paramCount > 0)
		script->Collect(paramCount);
	memcpy(script->m_aLVars, script->m_pScmFunction->vars, 64);
	script->m_dwIp = script->m_pScmFunction->retAddr;
	if(paramCount > 0)
		script->Store(paramCount);
	script->m_dwIp++;
	ScmFunction *prev = script->m_pScmFunction->prev;
	delete script->m_pScmFunction;
	script->m_pScmFunction = prev;
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_LABEL_OFFSET(CScript *script)
{
	script->Collect(1);
	if(game.Scripts.Params[0].nVar >= 0)
		game.Scripts.Params[0].pVar = &game.Scripts.Space[game.Scripts.Params[0].nVar];
	else
	{
		if(script->m_nScriptType == SCRIPT_TYPE_CUSTOM)
			game.Scripts.Params[0].pVar = &script->m_pCodeData[-game.Scripts.Params[0].nVar];
		else
			game.Scripts.Params[0].pVar = &game.Scripts.Space[0x20000 - game.Scripts.Params[0].nVar];
	}
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::GET_VAR_OFFSET(CScript *script)
{
	game.Scripts.Params[0].pVar = script->GetPointerToScriptVariable();
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::BIT_AND(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar & game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::BIT_OR(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar | game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::BIT_XOR(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar ^ game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::BIT_NOT(CScript *script)
{
	script->Collect(1);
	game.Scripts.Params[0].nVar = ~game.Scripts.Params[0].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::BIT_MOD(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar % game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::BIT_SHR(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar >> game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::BIT_SHL(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar << game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

//0400=7,store_coords_to %5d% %6d% %7d% from_object %1d% with_offset %2d% %3d% %4d%
eOpcodeResult CustomOpcodes::STORE_COORDS_FROM_OBJECT_WITH_OFFSET(CScript *script)
{
	script->Collect(4);
	void* object = game.Pools.pfObjectPoolGetStruct(*game.Pools.pObjectPool, game.Scripts.Params[0].nVar);

	CVector in;
	in.x = game.Scripts.Params[1].fVar;
	in.y = game.Scripts.Params[2].fVar;
	in.z = game.Scripts.Params[3].fVar;
	CVector out;
	game.Misc.Multiply3x3(&out, (uintptr_t*)((uintptr_t*)object + 4), &in);

	game.Scripts.Params[0].fVar = out.x + *(float*)((uintptr_t*)object + 52);
	game.Scripts.Params[1].fVar = out.y + *(float*)((uintptr_t*)object + 52 + 4);
	game.Scripts.Params[2].fVar = out.z + *(float*)((uintptr_t*)object + 52 + 8);

	script->Store(3);
	return OR_CONTINUE;
}

//0407=7,store_coords_to %5d% %6d% %7d% from_car %1d% with_offset %2d% %3d% %4d%
eOpcodeResult CustomOpcodes::STORE_COORDS_FROM_CAR_WITH_OFFSET(CScript *script)
{
	script->Collect(4);
	void* car = game.Pools.pfVehiclePoolGetStruct(*game.Pools.pVehiclePool, game.Scripts.Params[0].nVar);

	CVector in;
	in.x = game.Scripts.Params[1].fVar;
	in.y = game.Scripts.Params[2].fVar;
	in.z = game.Scripts.Params[3].fVar;
	CVector out;
	game.Misc.Multiply3x3(&out, (uintptr_t*)((uintptr_t*)car + 4), &in);

	game.Scripts.Params[0].fVar = out.x + *(float*)((uintptr_t*)car + 52);
	game.Scripts.Params[1].fVar = out.y + *(float*)((uintptr_t*)car + 52 + 4);
	game.Scripts.Params[2].fVar = out.z + *(float*)((uintptr_t*)car + 52 + 8);

	script->Store(3);
	return OR_CONTINUE;
}

//04C4=7,store_coords_to %5d% %6d% %7d% from_actor %1d% with_offset %2d% %3d% %4d%
eOpcodeResult CustomOpcodes::STORE_COORDS_FROM_ACTOR_WITH_OFFSET(CScript *script)
{
	script->Collect(4);
	void* actor = game.Pools.pfPedPoolGetStruct(*game.Pools.pPedPool, game.Scripts.Params[0].nVar);

	CVector in;
	in.x = game.Scripts.Params[1].fVar;
	in.y = game.Scripts.Params[2].fVar;
	in.z = game.Scripts.Params[3].fVar;
	CVector out;
	game.Misc.Multiply3x3(&out, (uintptr_t*)((uintptr_t*)actor + 4), &in);

	game.Scripts.Params[0].fVar = out.x + *(float*)((uintptr_t*)actor + 52);
	game.Scripts.Params[1].fVar = out.y + *(float*)((uintptr_t*)actor + 52 + 4);
	game.Scripts.Params[2].fVar = out.z + *(float*)((uintptr_t*)actor + 52 + 8);

	script->Store(3);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::STORE_PLAYER_CURRENTLY_ARMED_WEAPON(CScript *script)
{
	script->Collect(1);
	game.Scripts.Params[0].nVar = *(DWORD *)(game.Pools.pCPlayerPedPool[79 * game.Scripts.Params[0].nVar] + 24 * *(BYTE *)(game.Pools.pCPlayerPedPool[79 * game.Scripts.Params[0].nVar] + 1176) + 860);
	script->Store(1);
	return OR_CONTINUE;
}

eOpcodeResult CustomOpcodes::START_CUSTOM_THREAD_VSTRING(CScript *script)
{
	script->Collect(1);
	char filepath[MAX_PATH];
	strcpy(filepath, "cleo\\");
	strcat(filepath, game.Scripts.Params[0].cVar);
	CScript *newScript = new CScript(filepath);
	if(newScript && newScript->Loaded())
	{
		newScript->AddToCustomList(&scriptMgr.pCusomScripts);
		scriptMgr.numLoadedCustomScripts++;
		game.Scripts.AddScriptToList(newScript, game.Scripts.pActiveScriptsList);
		newScript->m_bIsActive = true;
		LOGL(LOG_PRIORITY_OPCODE, "START_CUSTOM_THREAD: Started new script \"%s\"", script->m_acName);
		for(int i = 0; script->GetNextParamType(); i++)
		{
			script->Collect(1);
			newScript->m_aLVars[i].nVar = game.Scripts.Params[0].nVar;
		}
		script->UpdateCompareFlag(true);
	}
	else
	{
		while(script->GetNextParamType())
			script->Collect(1);
		LOGL(LOG_PRIORITY_OPCODE, "START_CUSTOM_THREAD: Script loading failed, \"%s\"", script->m_acName);
		if(newScript)
			delete newScript;
		script->UpdateCompareFlag(false);
	}
	script->m_dwIp++;
	return OR_CONTINUE;
}

//0601=2, is_button_pressed_on_pad %1d% with_sensitivity %2d%
eOpcodeResult CustomOpcodes::IS_BUTTON_PRESSED_ON_PAD(CScript *script)
{
	script->Collect(2);
	script->UpdateCompareFlag(*(short*)((game.Scripts.Params[0].nVar * 2) + game.Misc.activePadState) == (short)game.Scripts.Params[1].nVar);
	return OR_CONTINUE;
}

//0602=2, emulate_button_press_on_pad %1d% with_sensitivity %2d%
eOpcodeResult CustomOpcodes::EMULATE_BUTTON_PRESS_ON_PAD(CScript *script)
{
	script->Collect(2);
	*(short*)((game.Scripts.Params[0].nVar * 2) + game.Misc.activePadState) = game.Scripts.Params[1].nVar;
	return OR_CONTINUE;
}

//0603=0, is_camera_in_widescreen_mode
eOpcodeResult CustomOpcodes::IS_CAMERA_IN_WIDESCREEN_MODE(CScript *script)
{
	script->UpdateCompareFlag(*(char*)game.Misc.cameraWidescreen != 0);
	return OR_CONTINUE;
}

//0604=2, %2d% = weapon %1d% model
eOpcodeResult CustomOpcodes::GET_MODEL_ID_FROM_WEAPON_ID(CScript *script)
{
	script->Collect(1);
	unsigned int wID = game.Misc.pfModelForWeapon(game.Scripts.Params[0].nVar);
	game.Scripts.Params[0].nVar = wID ? wID : -1;
	script->Store(1);
	return OR_CONTINUE;
}

//0605=2, %2d% = model %1d% weapon id
eOpcodeResult CustomOpcodes::GET_WEAPON_ID_FROM_MODEL_ID(CScript *script)
{
	script->Collect(1);
	unsigned int mID = game.Scripts.Params[0].nVar;
	for (size_t i = 0; i < 37; i++)
	{
		if (mID == game.Misc.pfModelForWeapon(i))
		{
			game.Scripts.Params[0].nVar = i;
			script->Store(1);
			return OR_CONTINUE;
		}
	}
	game.Scripts.Params[0].nVar = -1;
	script->Store(1);
	return OR_CONTINUE;
}

//0606=3, set_memory_offset memory_pointer %1d% memory_to_point %2d% virtual_protect %3d%
eOpcodeResult CustomOpcodes::SET_MEM_OFFSET(CScript *script)
{
	script->Collect(3);
	DWORD flOldProtect;
	if (game.Scripts.Params[2].nVar)
		VirtualProtect(game.Scripts.Params[0].pVar, game.Scripts.Params[1].nVar, PAGE_EXECUTE_READWRITE, &flOldProtect);

	*(int *)game.Scripts.Params[0].pVar = game.Scripts.Params[1].nVar - (game.Scripts.Params[0].nVar + 4);

	if (game.Scripts.Params[2].nVar)
		VirtualProtect(game.Scripts.Params[0].pVar, game.Scripts.Params[1].nVar, flOldProtect, &flOldProtect);
	return OR_CONTINUE;
}

//0607=1, %1d% = get_current_weather
eOpcodeResult CustomOpcodes::GET_CURRENT_WEATHER(CScript *script)
{
	game.Scripts.Params[0].nVar = *(short*)game.Misc.currentWeather;
	script->Store(1);
	return OR_CONTINUE;
}

//0608=3, show_text_position %1d% %2d% text %3d%
eOpcodeResult CustomOpcodes::SHOW_TEXT_POSITION(CScript *script)
{
	script->Collect(3);
	game.Text.textDrawers = (CTextDrawer *)(*(uintptr_t*)0x438BB9);
	game.Text.textDrawers[*game.Text.currentTextDrawer].x = game.Scripts.Params[0].fVar;
	game.Text.textDrawers[*game.Text.currentTextDrawer].y = game.Scripts.Params[1].fVar;
	const char *text = game.Scripts.Params[2].cVar;
	swprintf((wchar_t*)&game.Text.textDrawers[*game.Text.currentTextDrawer].text, 100, L"%hs", text);
	*game.Text.currentTextDrawer = *game.Text.currentTextDrawer + 1;
	return OR_CONTINUE;
};

//0609=-1, show_formatted_text_position %1d% %2d% text %3d%
eOpcodeResult CustomOpcodes::SHOW_FORMATTED_TEXT_POSITION(CScript *script)
{
	script->Collect(3);
	game.Text.textDrawers[*game.Text.currentTextDrawer].x = game.Scripts.Params[0].fVar;
	game.Text.textDrawers[*game.Text.currentTextDrawer].y = game.Scripts.Params[1].fVar;
	char fmt[100]; char text[100]; static wchar_t message_buf[0x80];
	strcpy(fmt, game.Scripts.Params[2].cVar);
	format(script, text, sizeof(text), fmt);
	swprintf((wchar_t*)&game.Text.textDrawers[*game.Text.currentTextDrawer].text, 100, L"%hs", text);
	while ((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	*game.Text.currentTextDrawer = *game.Text.currentTextDrawer + 1;
	return OR_CONTINUE;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/*****************************************************************************************************/
////////////////////////////////CLEO4 SA opcodes///////////////////////////////////////////////////////
//0A8C=4,write_memory %1d% size %2d% value %3d% virtual_protect %4d% //dup
//0A8D=4,%4d% = read_memory %1d% size %2d% virtual_protect %3d% //dup

//0A8E=3,%3d% = %1d% + %2d% ; int
eOpcodeResult CustomOpcodes::OPCODE_0A8E(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar + game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

//0A8F=3,%3d% = %1d% - %2d% ; int
eOpcodeResult CustomOpcodes::OPCODE_0A8F(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar - game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

//0A90=3,%3d% = %1d% * %2d% ; int
eOpcodeResult CustomOpcodes::OPCODE_0A90(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar * game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

//0A91=3,%3d% = %1d% / %2d% ; int
eOpcodeResult CustomOpcodes::OPCODE_0A91(CScript *script)
{
	script->Collect(2);
	game.Scripts.Params[0].nVar = game.Scripts.Params[0].nVar / game.Scripts.Params[1].nVar;
	script->Store(1);
	return OR_CONTINUE;
}

//0A92=-1,create_custom_thread %1s% //dup
//0A93=0,end_custom_thread //dup
//0A94=-1,start_custom_mission %1s% //not supported
//0A95=0,enable_thread_saving ////not supported
//0A96=2,%2d% = actor %1d% struct //dup
//0A97=2,%2d% = car %1d% struct //dup
//0A98=2,%2d% = object %1d% struct //dup

//0A99=1,chdir %1buserdir/rootdir%
eOpcodeResult CustomOpcodes::OPCODE_0A99(CScript *script)
{
	script->Collect(1);
	auto paramType = script->GetNextParamType();
	if (paramType != PARAM_TYPE_STRING)
	{
		_chdir(game.Scripts.Params[0].nVar ? game.Misc.pfGetUserDirectory() : "");
	}
	else
	{
		_chdir(game.Scripts.Params[0].cVar);
	}
	return OR_CONTINUE;
}


//0A9A=3,%3d% = openfile %1s% mode %2d% ; IF and SET
eOpcodeResult CustomOpcodes::OPCODE_0A9A(CScript *script)
{
	script->Collect(1);
	const char *fname = game.Scripts.Params[0].cVar;
	auto paramType = script->GetNextParamType();
	script->Collect(1);
	char mode[0x10];

	if (paramType != PARAM_TYPE_STRING)
	{
		union
		{
			unsigned uParam;
			char strParam[4];
		}param;
		param.uParam = game.Scripts.Params[0].nVar;
		strcpy(mode, param.strParam);
	}
	else
		strcpy(mode, game.Scripts.Params[0].cVar);

	auto file = fopen(fname, mode);
	game.Scripts.Params[0].pVar = file;
	script->UpdateCompareFlag(file != nullptr);
	if (file) game.Misc.openedFiles->insert(file);
	script->Store(1);
	return OR_CONTINUE;
}

//0A9B=1,closefile %1d%
eOpcodeResult CustomOpcodes::OPCODE_0A9B(CScript *script)
{
	script->Collect(1);
	fclose((FILE *)game.Scripts.Params[0].pVar);
	game.Misc.openedFiles->erase((FILE *)game.Scripts.Params[0].pVar);
	return OR_CONTINUE;
}

//0A9C=2,%2d% = file %1d% size
eOpcodeResult CustomOpcodes::OPCODE_0A9C(CScript *script)
{
	script->Collect(1);
	FILE *file;
	file = (FILE *)game.Scripts.Params[0].pVar;
	auto savedPos = ftell(file);
	fseek(file, 0, SEEK_END);
	game.Scripts.Params[0].nVar = static_cast<unsigned>(ftell(file));
	fseek(file, savedPos, SEEK_SET);
	script->Store(1);
	return OR_CONTINUE;
}

//0A9D=3,readfile %1d% size %2d% to %3d%
eOpcodeResult CustomOpcodes::OPCODE_0A9D(CScript *script)
{
	script->Collect(3);
	FILE *file;
	file = (FILE *)game.Scripts.Params[0].pVar;
	unsigned size = game.Scripts.Params[1].nVar;
	void *buf;
	buf = game.Scripts.Params[2].cVar;
	fread(buf, size, 1, file);
	return OR_CONTINUE;
}

//0A9E=3,writefile %1d% size %2d% from %3d%
eOpcodeResult CustomOpcodes::OPCODE_0A9E(CScript *script)
{
	script->Collect(3);
	FILE *file;
	file = (FILE *)game.Scripts.Params[0].pVar;
	unsigned size = game.Scripts.Params[1].nVar;
	const void *buf;
	buf = game.Scripts.Params[2].cVar;
	fwrite(buf, size, 1, file);
	fflush(file);
	return OR_CONTINUE;
}

//0A9F=1,%1d% = current_thread_pointer //dup


//0AA0=1,gosub_if_false %1p%
eOpcodeResult CustomOpcodes::OPCODE_0AA0(CScript *script)
{
	script->Collect(1);
	script->m_aGosubAddr[script->m_nCurrentGosub++] = script->m_dwIp;
	if (!script->m_bCondResult)
		script->JumpTo(game.Scripts.Params[0].nVar);
	return OR_CONTINUE;
}

//0AA1=0,return_if_false
eOpcodeResult CustomOpcodes::OPCODE_0AA1(CScript *script)
{
	if (script->m_bCondResult) return OR_CONTINUE;
	script->m_dwIp = script->m_aGosubAddr[--script->m_nCurrentGosub];
	return OR_CONTINUE;
}

//0AA2=2,%2h% = load_library %1s% ; IF and SET
eOpcodeResult CustomOpcodes::OPCODE_0AA2(CScript *script)
{
	script->Collect(1);
	auto libHandle = LoadLibrary(game.Scripts.Params[0].cVar);
	game.Scripts.Params[0].pVar = libHandle;
	script->Store(1);
	script->UpdateCompareFlag(libHandle != nullptr);
	return OR_CONTINUE;
}

//0AA3=1,free_library %1h%
eOpcodeResult CustomOpcodes::OPCODE_0AA3(CScript *script)
{
	script->Collect(1);
	HMODULE libHandle;
	libHandle = (HMODULE)game.Scripts.Params[0].pVar;
	FreeLibrary(libHandle);
	return OR_CONTINUE;
}

//0AA4=3,%3d% = get_proc_address %1s% library %2d% ; IF and SET
eOpcodeResult CustomOpcodes::OPCODE_0AA4(CScript *script)
{
	script->Collect(2);
	char *funcName = game.Scripts.Params[0].cVar;
	HMODULE libHandle;
	libHandle = (HMODULE)game.Scripts.Params[1].pVar;
	void *funcAddr = (void *)GetProcAddress(libHandle, funcName);
	game.Scripts.Params[0].pVar = funcAddr;
	script->Store(1);
	script->UpdateCompareFlag(funcAddr != nullptr);
	return OR_CONTINUE;
}

//0AA5=-1,call %1d% num_params %2h% pop %3h% //dup
//0AA6=-1,call_method %1d% struct %2d% num_params %3h% pop %4h% //dup
//0AA7=-1,call_function %1d% num_params %2h% pop %3h% //dup
//0AA8=-1,call_function_method %1d% struct %2d% num_params %3h% pop %4h% //dup


//0AA9=0,  is_game_version_original
eOpcodeResult CustomOpcodes::OPCODE_0AA9(CScript *script)
{
	script->UpdateCompareFlag(game.GetGameVersion() == GAME_V1_0);
	return OR_CONTINUE;
}
//0AAA=2,%2d% = thread %1s% pointer //dup


//0AAB=1,   file_exists %1s%
eOpcodeResult CustomOpcodes::OPCODE_0AAB(CScript *script)
{
	script->Collect(1);
	DWORD fAttr = GetFileAttributes(game.Scripts.Params[0].cVar);
	script->UpdateCompareFlag((fAttr != INVALID_FILE_ATTRIBUTES) &&
		!(fAttr & FILE_ATTRIBUTE_DIRECTORY));
	return OR_CONTINUE;
}

//0AAC=2,%2d% = load_audiostream %1d%
//0AAD=2,set_mp3 %1d% perform_action %2d%
//0AAE=1,release_mp3 %1d%
//0AAF=2,%2d% = get_mp3_length %1d%

//0AB0=1,  key_pressed %1d% //dup
//0AB1=-1,call_scm_func %1p% //dup
//0AB2=-1,ret  //dup
//0AB3=2,var %1d% = %2d% //not supported
//0AB4=2,%2d% = var %1d% //not supported
//0AB5=3,store_actor %1d% closest_vehicle_to %2d% closest_ped_to %3d%
//0AB6=3,store_target_marker_coords_to %1d% %2d% %3d% // IF and SET //not supported
//0AB7=2,get_vehicle %1d% number_of_gears_to %2d%
//0AB8=2,get_vehicle %1d% current_gear_to %2d%
//0AB9=2,get_mp3 %1d% state_to %2d%
//0ABA=1,end_custom_thread_named %1s% //dup
//0ABB=2,%2d% = audiostream %1d% volume
//0ABC=2,set_audiostream %1d% volume %2d%
//0ABD=1,  vehicle %1d% siren_on
//0ABE=1,  vehicle %1d% engine_on
//0ABF=2,set_vehicle %1d% engine_state_to %2d%
//0AC0=2,audiostream %1d% loop %2d%
//0AC1=2,%2d% = load_audiostream_with_3d_support %1d% ; IF and SET
//0AC2=4,set_audiostream %1d% 3d_position %2d% %3d% %4d%
//0AC3=2,link_3d_audiostream %1d% to_object %2d%
//0AC4=2,link_3d_audiostream %1d% to_actor %2d%
//0AC5=2,link_3d_audiostream %1d% to_vehicle %2d%


//0AC6=2,%2d% = label %1p% offset //dup
//0AC7=2,%2d% = var %1d% offset //dup


//0AC8=2,%2d% = allocate_memory_size %1d%
eOpcodeResult CustomOpcodes::OPCODE_0AC8(CScript *script)
{
	script->Collect(1);
	unsigned size = game.Scripts.Params[0].nVar;
	void *mem = calloc(size, sizeof(char));
	if (mem)
	{
		game.Misc.allocatedMemory->insert(mem);
		game.Scripts.Params[0].pVar = mem;
		script->UpdateCompareFlag(true);
	}
	else script->UpdateCompareFlag(false);
	script->Store(1);
	return OR_CONTINUE;
};

//0AC9=1,free_allocated_memory %1d%
eOpcodeResult CustomOpcodes::OPCODE_0AC9(CScript *script)
{
	script->Collect(1);
	void *mem = game.Scripts.Params[0].pVar;
	free(mem);
	game.Misc.allocatedMemory->erase(mem);
	return OR_CONTINUE;
};

//0ACA=1,show_text_box %1s%
eOpcodeResult CustomOpcodes::OPCODE_0ACA(CScript *script)
{
	static wchar_t message_buf[0x80];
	script->Collect(1);
	swprintf(message_buf, 100, L"%hs", game.Scripts.Params[0].cVar);
	game.Text.TextBox(message_buf, false);
	return OR_CONTINUE;
};

//0ACB=3,show_styled_text %1s% time %2d% style %3d%
eOpcodeResult CustomOpcodes::OPCODE_0ACB(CScript *script)
{
	static wchar_t message_buf[0x80];
	script->Collect(3);
	const char *text = game.Scripts.Params[0].cVar;
	unsigned time, style;
	swprintf(message_buf, 100, L"%hs", text);
	game.Text.StyledText(message_buf, game.Scripts.Params[1].nVar, game.Scripts.Params[2].nVar - 1);
	return OR_CONTINUE;
};

//0ACC=2,show_text_lowpriority %1s% time %2d%
eOpcodeResult CustomOpcodes::OPCODE_0ACC(CScript *script)
{
	static wchar_t message_buf[0x80];
	script->Collect(2);
	const char *text = game.Scripts.Params[0].cVar;
	swprintf(message_buf, 100, L"%hs", text);
	game.Text.TextLowPriority(message_buf, game.Scripts.Params[1].nVar, false, false);
	return OR_CONTINUE;
};

//0ACD=2,show_text_highpriority %1s% time %2d%
eOpcodeResult CustomOpcodes::OPCODE_0ACD(CScript *script)
{
	static wchar_t message_buf[0x80];
	script->Collect(2);
	const char *text = game.Scripts.Params[0].cVar;
	swprintf(message_buf, 100, L"%hs", text);
	game.Text.TextHighPriority(message_buf, game.Scripts.Params[1].nVar, false, false);
	return OR_CONTINUE;
};

//0ACE=-1,show_formatted_text_box %1s%
eOpcodeResult CustomOpcodes::OPCODE_0ACE(CScript *script)
{
	static wchar_t message_buf[0x80];
	script->Collect(1);
	char fmt[100]; char text[100];
	strcpy(fmt, game.Scripts.Params[0].cVar);
	format(script, text, sizeof(text), fmt);

	swprintf(message_buf, 100, L"%hs", text);
	game.Text.TextBox(message_buf, false);

	while ((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
};

//0ACF=-1,show_formatted_styled_text %1s% time %2d% style %3d%
eOpcodeResult CustomOpcodes::OPCODE_0ACF(CScript *script)
{
	script->Collect(3);
	char fmt[100]; char text[100]; static wchar_t message_buf[100];
	unsigned time, style;
	strcpy(fmt, game.Scripts.Params[0].cVar);
	time = game.Scripts.Params[1].nVar;
	style = game.Scripts.Params[2].nVar;
	format(script, text, sizeof(text), fmt);
	swprintf(message_buf, 100, L"%hs", text);
	game.Text.StyledText(message_buf, time, style - 1);
	while ((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
};

//0AD0=-1,show_formatted_text_lowpriority %1s% time %2s%
eOpcodeResult CustomOpcodes::OPCODE_0AD0(CScript *script)
{
	script->Collect(2);
	char fmt[100]; char text[100]; static wchar_t message_buf[0x80];
	unsigned time;
	strcpy(fmt, game.Scripts.Params[0].cVar);
	time = game.Scripts.Params[1].nVar;
	format(script, text, sizeof(text), fmt);
	swprintf(message_buf, 100, L"%hs", text);
	game.Text.TextLowPriority(message_buf, time, false, false);
	while ((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
};

//0AD1=-1,show_formatted_text_highpriority %1s% time %2s%
eOpcodeResult CustomOpcodes::OPCODE_0AD1(CScript *script)
{
	script->Collect(2);
	char fmt[100]; char text[100]; static wchar_t message_buf[0x80];
	unsigned time;
	strcpy(fmt, game.Scripts.Params[0].cVar);
	time = game.Scripts.Params[1].nVar;
	format(script, text, sizeof(text), fmt);
	swprintf(message_buf, 100, L"%hs", text);
	game.Text.TextHighPriority(message_buf, time, false, false);
	while ((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
};

//0AD2=2,%2d% = player %1d% targeted_actor //IF and SET

//0AD3=-1,string %1d% format %2d%
eOpcodeResult CustomOpcodes::OPCODE_0AD3(CScript *script)
{
	script->Collect(2);
	char fmt[100], *dst;
	dst = (char*)game.Scripts.Params[0].pVar;
	strcpy(fmt, game.Scripts.Params[1].cVar);
	format(script, dst, -1ul, fmt);
	while ((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
};

//0AD4=-1,  scan_string %1d% format %2s% store_num_results_to %3d%
eOpcodeResult CustomOpcodes::OPCODE_0AD4(CScript *script)
{
	script->Collect(2);
	char fmt[100], *src;
	src = game.Scripts.Params[0].cVar;
	strcpy(fmt, game.Scripts.Params[1].cVar);
	size_t cExParams = 0;
	int *result = (int *)script->GetPointerToScriptVariable();
	tScriptVar *ExParams[35];
	// read extra params
	while ((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
	{
		ExParams[cExParams++] = (tScriptVar *)script->GetPointerToScriptVariable();
	}
	script->m_dwIp++;

	*result = sscanf(src, fmt,
		ExParams[0], ExParams[1], ExParams[2], ExParams[3], ExParams[4], ExParams[5],
		ExParams[6], ExParams[7], ExParams[8], ExParams[9], ExParams[10], ExParams[11],
		ExParams[12], ExParams[13], ExParams[14], ExParams[15], ExParams[16], ExParams[17],
		ExParams[18], ExParams[19], ExParams[20], ExParams[21], ExParams[22], ExParams[23],
		ExParams[24], ExParams[25], ExParams[26], ExParams[27], ExParams[28], ExParams[29],
		ExParams[30], ExParams[31], ExParams[32], ExParams[33], ExParams[34]);
	return OR_CONTINUE;
};

//0AD5=3,file %1d% seek %2d% from_origin %3d% //IF and SET
eOpcodeResult CustomOpcodes::OPCODE_0AD5(CScript *script)
{
	script->Collect(3);
	FILE* file = (FILE*)game.Scripts.Params[0].pVar;
	int seek = game.Scripts.Params[1].nVar;
	int origin = game.Scripts.Params[2].nVar;
	script->UpdateCompareFlag(fseek(file, seek, origin) == 0);
	return OR_CONTINUE;
};

//0AD6=1, end_of_file %1d% reached
eOpcodeResult CustomOpcodes::OPCODE_0AD6(CScript *script)
{
	script->Collect(1);
	FILE* file = (FILE*)game.Scripts.Params[0].pVar;
	script->UpdateCompareFlag(feof(file) != 0);
	return OR_CONTINUE;
};

//0AD7=3,read_string_from_file %1d% to %2d% size %3d% // IF and SET
eOpcodeResult CustomOpcodes::OPCODE_0AD7(CScript *script)
{
	script->Collect(3);
	FILE* file = (FILE*)game.Scripts.Params[0].pVar;
	char* buf = (char*)game.Scripts.Params[1].pVar;
	unsigned size = game.Scripts.Params[2].nVar;
	script->UpdateCompareFlag(fgets(buf, size, file) == buf);
	return OR_CONTINUE;
};

//0AD8=2,write_string_to_file %1d% from %2d% //IF and SET
eOpcodeResult CustomOpcodes::OPCODE_0AD8(CScript *script)
{
	script->Collect(2);
	FILE* file = (FILE*)game.Scripts.Params[0].pVar;
	char* buf = (char*)game.Scripts.Params[1].pVar;
	script->UpdateCompareFlag(fputs(buf, file) > 0);
	fflush(file);
	return OR_CONTINUE;
};

//0AD9=-1,write_formatted_text %2d% in_file %1d%
eOpcodeResult CustomOpcodes::OPCODE_0AD9(CScript *script)
{
	script->Collect(2);
	char fmt[100]; char text[100];
	FILE* file = (FILE*)game.Scripts.Params[1].pVar;
	strcpy(fmt, game.Scripts.Params[1].cVar);
	format(script, text, sizeof(text), fmt);
	fputs(text, file);
	fflush(file);
	while ((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
		script->Collect(1);
	script->m_dwIp++;
	return OR_CONTINUE;
};

//0ADA=-1,%3d% = scan_file %1d% format %2d% //IF and SET
eOpcodeResult CustomOpcodes::OPCODE_0ADA(CScript *script)
{
	script->Collect(2);
	char fmt[100];
	FILE* file = (FILE*)game.Scripts.Params[0].pVar;
	strcpy(fmt, game.Scripts.Params[1].cVar);
	size_t cExParams = 0;
	int *result = (int *)script->GetPointerToScriptVariable();
	tScriptVar *ExParams[35];
	// read extra params
	while ((*(tParamType *)(&game.Scripts.Space[script->m_dwIp])).type)
	{
		ExParams[cExParams++] = (tScriptVar *)script->GetPointerToScriptVariable();
	}
	script->m_dwIp++;

	*result = fscanf(file, fmt,
		ExParams[0], ExParams[1], ExParams[2], ExParams[3], ExParams[4], ExParams[5],
		ExParams[6], ExParams[7], ExParams[8], ExParams[9], ExParams[10], ExParams[11],
		ExParams[12], ExParams[13], ExParams[14], ExParams[15], ExParams[16], ExParams[17],
		ExParams[18], ExParams[19], ExParams[20], ExParams[21], ExParams[22], ExParams[23],
		ExParams[24], ExParams[25], ExParams[26], ExParams[27], ExParams[28], ExParams[29],
		ExParams[30], ExParams[31], ExParams[32], ExParams[33], ExParams[34]);
	return OR_CONTINUE;
};

//0ADB=2,%2d% = car_model %1o% name
eOpcodeResult CustomOpcodes::OPCODE_0ADB(CScript *script)
{
	script->Collect(2);
	unsigned mi = game.Scripts.Params[0].nVar;
	char *result = game.Scripts.Params[1].cVar;
	char *gxt = (char*)((game.Misc.stVehicleModelInfo + 0x36) + ((mi - 90) * 0x1F8));
	wchar_t *text = CustomText::GetText(game.Text.CText, 0, gxt);
	wcstombs(result, text, wcslen(text));
	return OR_CONTINUE;
}

//0ADC=1,   test_cheat %1d%
eOpcodeResult CustomOpcodes::OPCODE_0ADC(CScript *script)
{
	script->Collect(1);

	char *c = game.Text.cheatString;
	char buf[30];
	strcpy(buf, game.Scripts.Params[0].cVar);
	char *s = _strrev(buf);
	while (*s && toupper(*s++) == *c++);
	if (*s)
	{
		script->UpdateCompareFlag(false);
		return OR_CONTINUE;
	}
	game.Text.cheatString[0] = 0;
	script->UpdateCompareFlag(true);

	return OR_CONTINUE;
}

//0ADD=1,spawn_car_with_model %1o% like_a_cheat
eOpcodeResult CustomOpcodes::OPCODE_0ADD(CScript *script)
{
	script->Collect(1);
	game.Misc.pfSpawnCar(game.Scripts.Params[0].nVar);
	return OR_CONTINUE;
}

//0ADE=2,%2d% = text_by_GXT_entry %1d%
eOpcodeResult CustomOpcodes::OPCODE_0ADE(CScript *script)
{
	script->Collect(2);
	char *gxt = game.Scripts.Params[0].cVar;
	char *result = game.Scripts.Params[1].cVar;
	wchar_t *text = CustomText::GetText(game.Text.CText, 0, gxt);
	wcstombs(result, text, wcslen(text));
	return OR_CONTINUE;
}

//0ADF=2,add_dynamic_GXT_entry %1d% text %2d%
eOpcodeResult CustomOpcodes::OPCODE_0ADF(CScript *script)
{
	script->Collect(2);

	CustomTextEntry *entry = new CustomTextEntry(game.Scripts.Params[0].cVar, game.Scripts.Params[1].cVar);
	if (entry)
	{
		entry->m_pNext = CustomText::pCustomTextList;
		CustomText::pCustomTextList = entry;
	}

	return OR_CONTINUE;
}

//0AE0=1,remove_dynamic_GXT_entry %1d%
eOpcodeResult CustomOpcodes::OPCODE_0AE0(CScript *script)
{
	script->Collect(1);

	CustomTextEntry *entry = CustomText::pCustomTextList;
	while (entry)
	{
		CustomTextEntry *next = entry->m_pNext;
		if (next)
		{
			if (strcmp(game.Scripts.Params[0].cVar, next->m_key) == 0)
			{
				if (entry->m_pNext != next->m_pNext)
					entry->m_pNext = next->m_pNext;
				else
					entry->m_pNext = 0;

				LOGL(LOG_PRIORITY_CUSTOM_TEXT, "Unloaded custom text \"%s\"", next->m_key);
				delete next;
				return OR_CONTINUE;
			}
			else
			{
				if (strcmp(game.Scripts.Params[0].cVar, entry->m_key) == 0)
				{
					CustomText::pCustomTextList = next;
					LOGL(LOG_PRIORITY_CUSTOM_TEXT, "Unloaded custom text \"%s\"", entry->m_key);
					delete entry;
					return OR_CONTINUE;
				}
			}
		}
		else
		{
			if (strcmp(game.Scripts.Params[0].cVar, entry->m_key) == 0)
			{
				LOGL(LOG_PRIORITY_CUSTOM_TEXT, "Unloaded custom text \"%s\"", entry->m_key);
				delete entry;
				CustomText::pCustomTextList = 0;
				return OR_CONTINUE;
			}
		}
	}
	return OR_CONTINUE;
}

//0AE1=7,%7d% = random_actor_near_point %1d% %2d% %3d% in_radius %4d% find_next %5h% pass_deads %6h% //IF and SET //dup
//0AE2=7,%7d% = random_vehicle_near_point %1d% %2d% %3d% in_radius %4d% find_next %5h% pass_wrecked %6h% //IF and SET //dup
//0AE3=6,%6d% = random_object_near_point %1d% %2d% %3d% in_radius %4d% find_next %5h% //IF and SET //dup
//0AE4=1,directory_exists %1d%
//0AE5=1,create_directory %1d% ; IF and SET


//0AE6=3,%2d% = find_first_file %1d% get_filename_to %3d% ; IF and SET


//0AE7=2,%2d% = find_next_file %1d% ; IF and SET


//0AE8=1,find_close %1d%


//0AE9=1,pop_float %1d% //dup
//0AEA=2,%2d% = actor_struct %1d% handle //dup
//0AEB=2,%2d% = car_struct %1d% handle //dup
//0AEC=2,%2d% = object_struct %1d% handle //dup
//0AED=3,%3d% = float %1d% to_string_format %2d%
//0AEE=3,%3d% = exp %1d% base %2d% //all floats //dup
//0AEF=3,%3d% = log %1d% base %2d% //all floats //dup

// perform 'sprintf'-operation for parameters, passed through SCM
int format(CScript *script, char *str, size_t len, const char *format)
{
	unsigned int written = 0;
	const char *iter = format;
	char bufa[256], fmtbufa[64], *fmta;

	while (*iter)
	{
		while (*iter && *iter != '%')
		{
			if (written++ >= len)
				return -1;
			*str++ = *iter++;
		}
		if (*iter == '%')
		{
			if (iter[1] == '%')
			{
				if (written++ >= len)
					return -1;
				*str++ = '%'; /* "%%"->'%' */
				iter += 2;
				continue;
			}

			//get flags and width specifier
			fmta = fmtbufa;
			*fmta++ = *iter++;
			while (*iter == '0' ||
				*iter == '+' ||
				*iter == '-' ||
				*iter == ' ' ||
				*iter == '*' ||
				*iter == '#')
			{
				if (*iter == '*')
				{
					char *buffiter = bufa;
					//get width
					script->Collect(1);
					_itoa(game.Scripts.Params[0].nVar, buffiter, 10);
					while (*buffiter)
						*fmta++ = *buffiter++;
				}
				else
					*fmta++ = *iter;
				iter++;
			}

			//get immidiate width value
			while (isdigit(*iter))
				*fmta++ = *iter++;

			//get precision
			if (*iter == '.')
			{
				*fmta++ = *iter++;
				if (*iter == '*')
				{
					char *buffiter = bufa;
					script->Collect(1);
					_itoa(game.Scripts.Params[0].nVar, buffiter, 10);
					while (*buffiter)
						*fmta++ = *buffiter++;
				}
				else
					while (isdigit(*iter))
						*fmta++ = *iter++;
			}
			//get size
			if (*iter == 'h' || *iter == 'l')
				*fmta++ = *iter++;

			switch (*iter)
			{
			case 's':
			{
				static const char none[] = "(null)";
				const char *astr = game.Scripts.Params[0].cVar;
				const char *striter = astr ? astr : none;
				while (*striter)
				{
					if (written++ >= len)
						return -1;
					*str++ = *striter++;
				}
				iter++;
				break;
			}

			case 'c':
				if (written++ >= len)
					return -1;
				script->Collect(1);
				*str++ = (char)game.Scripts.Params[0].nVar;
				iter++;
				break;

			default:
			{
				/* For non wc types, use system sprintf and append to wide char output */
				/* FIXME: for unrecognised types, should ignore % when printing */
				char *bufaiter = bufa;
				if (*iter == 'p' || *iter == 'P')
				{
					script->Collect(1);
					sprintf(bufaiter, "%08X", game.Scripts.Params[0].nVar);
				}
				else
				{
					*fmta++ = *iter;
					*fmta = '\0';
					if (*iter == 'a' || *iter == 'A' ||
						*iter == 'e' || *iter == 'E' ||
						*iter == 'f' || *iter == 'F' ||
						*iter == 'g' || *iter == 'G')
					{
						script->Collect(1);
						sprintf(bufaiter, fmtbufa, game.Scripts.Params[0].fVar);
					}
					else
					{
						script->Collect(1);
						sprintf(bufaiter, fmtbufa, game.Scripts.Params[0].pVar);
					}
				}
				while (*bufaiter)
				{
					if (written++ >= len)
						return -1;
					*str++ = *bufaiter++;
				}
				iter++;
				break;
			}
			}
		}
	}
	if (written >= len)
		return -1;
	*str++ = 0;
	return (int)written;
}
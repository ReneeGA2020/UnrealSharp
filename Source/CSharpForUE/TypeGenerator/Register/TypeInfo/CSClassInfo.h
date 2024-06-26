﻿#pragma once

#include "CSTypeInfo.h"
#include "CSharpForUE/TypeGenerator/Register/CSGeneratedClassBuilder.h"
#include "CSharpForUE/TypeGenerator/Register/CSMetaData.h"
#include "UObject/Class.h"

class FCSGeneratedClassBuilder;

struct CSHARPFORUE_API FCSharpClassInfo : TCSharpTypeInfo<FClassMetaData, UClass, FCSGeneratedClassBuilder>
{
	FCSharpClassInfo(const TSharedPtr<FJsonValue>& MetaData) : TCSharpTypeInfo(MetaData)
	{
		TypeHandle = FCSManager::Get().GetTypeHandle(*TypeMetaData);
	}
	
	FCSharpClassInfo() {};

	// TCharpTypeInfo interface implementation
	virtual UClass* InitializeBuilder() override;
	// End of implementation
	
	// Pointer to the TypeHandle in CSharp
	uint8* TypeHandle;
};

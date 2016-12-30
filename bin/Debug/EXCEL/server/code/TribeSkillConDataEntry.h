// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TribeSkillConDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TRIBESKILLCONDATALOADER_H
#define _TRIBESKILLCONDATALOADER_H

#include <string>
#include <vector>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TribeSkillConDataEntry
{
	TribeSkillConDataEntry() : id(0), level(0), silver(0), contribution(0), libLevel(0), playerLevel(0){}
	virtual ~TribeSkillConDataEntry(){ }
	virtual UInt32 GetKey() const { return 0xFFFFFFFF; };
	/**
	帮会技能id
	**/
	UInt16	id;

	/**
	名字
	**/
	string	name;

	/**
	技能等级
	**/
	UInt8	level;

	/**
	升级消耗银币
	**/
	UInt32	silver;

	/**
	升级消耗贡献
	**/
	UInt32	contribution;

	/**
	需求书院等级
	**/
	UInt8	libLevel;

	/**
	需要玩家等级
	**/
	UInt8	playerLevel;
}; // TribeSkillConDataEntry define end

//data visitor for the excel table
template <typename T>
class TribeSkillConDataEntryVisitor
{
public:
	TribeSkillConDataEntryVisitor(){ static_assert(std::is_base_of<TribeSkillConDataEntry, T>::value != 0, "T must be inherited from TribeSkillConDataEntry"); }
	virtual ~TribeSkillConDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TribeSkillConDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TribeSkillConDataLoader(){ static_assert(std::is_base_of<TribeSkillConDataEntry, T>::value != 0, "T must be inherited from TribeSkillConDataEntry"); }
	~TribeSkillConDataLoader(){ ClearData(); }

	virtual bool ParseData(T* pT)
	{
		return true;
	}

	virtual bool AfterLoad()
	{
		return true;
	}

	bool LoadData(const std::string& strPath)
	{
		ClearData();
		Avalon::XmlDocument doc(strPath);
		if(!doc.LoadFile()) return false;
		Avalon::XmlElement* pElemRoot = doc.RootElement();
		if(pElemRoot == NULL)
		{
			return false;
		}
		TiXmlElement* pDataElem = doc.FirstChildElement(pElemRoot, "Row");
		UInt32 autoIncKey = 0;
		while(pDataElem != NULL)
		{
			T* pData = new T;
			doc.GetAttribute(pDataElem, "id", pData->id);
			doc.GetAttribute(pDataElem, "name", pData->name);
			doc.GetAttribute(pDataElem, "level", pData->level);
			doc.GetAttribute(pDataElem, "silver", pData->silver);
			doc.GetAttribute(pDataElem, "contribution", pData->contribution);
			doc.GetAttribute(pDataElem, "libLevel", pData->libLevel);
			doc.GetAttribute(pDataElem, "playerLevel", pData->playerLevel);
			if(!ParseData(pData)) return false;
			if(pData->GetKey() != 0xFFFFFFFF)
			{
				if(!_mapData.insert(std::make_pair(pData->GetKey(), pData)).second)
				{
					delete pData;
					ClearData();
					return false;
				}
			}
			else
			{
				if(!_mapData.insert(std::make_pair(++autoIncKey, pData)).second)
					delete pData;
			}
			pDataElem = doc.NextElement(pDataElem);
		}
		return AfterLoad();
	}

	void VisitData(TribeSkillConDataEntryVisitor<T>& visitor)
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end(); ++itr)
		{
			if(!visitor(itr->second))
				return;
		}
	}

	T* FindEntry(UInt32 key)
	{
		auto itr = _mapData.find(key);
		if(itr != _mapData.end())
			return itr->second;
		return NULL;
	}

	void ClearData()
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end();++itr)
		{
			const T *p = itr->second;
			delete p;
		}
		_mapData.clear();
	}
};

#endif


// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     SkillListDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _SKILLLISTDATALOADER_H
#define _SKILLLISTDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct SkillListDataEntry
{
	SkillListDataEntry() : skill(0), occu(0), type(0), needlevel(0), stage(0), item(0){}
	virtual ~SkillListDataEntry(){ }
	virtual UInt32 GetKey() const { return skill; }
	/**
	技能ID
	**/
	UInt16	skill;

	/**
	职业
	**/
	UInt8	occu;

	/**
	类型
	**/
	UInt8	type;

	/**
	需要等级
	**/
	UInt16	needlevel;

	/**
	需要阶段
	**/
	UInt8	stage;

	/**
	激活道具
	**/
	UInt16	item;
}; // SkillListDataEntry define end

//data visitor for the excel table
template <typename T>
class SkillListDataEntryVisitor
{
public:
	SkillListDataEntryVisitor(){ static_assert(std::is_base_of<SkillListDataEntry, T>::value != 0, "T must be inherited from SkillListDataEntry"); }
	virtual ~SkillListDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class SkillListDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	SkillListDataLoader(){ static_assert(std::is_base_of<SkillListDataEntry, T>::value != 0, "T must be inherited from SkillListDataEntry"); }
	~SkillListDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "skill", pData->skill);
			doc.GetAttribute(pDataElem, "occu", pData->occu);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "needlevel", pData->needlevel);
			doc.GetAttribute(pDataElem, "stage", pData->stage);
			doc.GetAttribute(pDataElem, "item", pData->item);
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

	void VisitData(SkillListDataEntryVisitor<T>& visitor)
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


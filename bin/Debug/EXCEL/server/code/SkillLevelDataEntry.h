// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     SkillLevelDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _SKILLLEVELDATALOADER_H
#define _SKILLLEVELDATALOADER_H

#include <string>
#include <vector>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct SkillLevelDataEntry
{
	SkillLevelDataEntry() : id(0), level(0), playerLevel(0), taskId(0), needSilver(0), needCrystal(0), canforget(0), forgetmoney(0), needhp(0), cd(0), preparetime(0), function1(0), param11(0), param12(0), param13(0), function2(0), param21(0), param22(0), param23(0), function3(0), param31(0), param32(0), param33(0){}
	virtual ~SkillLevelDataEntry(){ }
	virtual UInt32 GetKey() const { return 0xFFFFFFFF; };
	/**
	技能id
	**/
	UInt16	id;

	/**
	名称
	**/
	string	name;

	/**
	技能级别
	**/
	UInt16	level;

	/**
	开启等级
	**/
	UInt8	playerLevel;

	/**
	开启任务
	**/
	UInt32	taskId;

	/**
	银币消耗
	**/
	UInt32	needSilver;

	/**
	玄晶消耗
	**/
	UInt32	needCrystal;

	/**
	是否可以遗忘
	**/
	UInt8	canforget;

	/**
	遗忘金钱消耗
	**/
	UInt32	forgetmoney;

	/**
	生命消耗
	**/
	UInt32	needhp;

	/**
	技能cd
	**/
	UInt32	cd;

	/**
	吟唱时间
	**/
	UInt32	preparetime;

	/**
	效果函数1
	**/
	UInt8	function1;

	/**
	效果函数1参数1
	**/
	UInt32	param11;

	/**
	效果函数1参数2
	**/
	UInt32	param12;

	/**
	效果函数1参数3
	**/
	UInt32	param13;

	/**
	效果函数2
	**/
	UInt8	function2;

	/**
	效果函数2参数1
	**/
	UInt32	param21;

	/**
	效果函数2参数2
	**/
	UInt32	param22;

	/**
	效果函数2参数3
	**/
	UInt32	param23;

	/**
	效果函数3
	**/
	UInt8	function3;

	/**
	效果函数3参数1
	**/
	UInt32	param31;

	/**
	效果函数3参数2
	**/
	UInt32	param32;

	/**
	效果函数3参数3
	**/
	UInt32	param33;
}; // SkillLevelDataEntry define end

//data visitor for the excel table
template <typename T>
class SkillLevelDataEntryVisitor
{
public:
	SkillLevelDataEntryVisitor(){ static_assert(std::is_base_of<SkillLevelDataEntry, T>::value != 0, "T must be inherited from SkillLevelDataEntry"); }
	virtual ~SkillLevelDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class SkillLevelDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	SkillLevelDataLoader(){ static_assert(std::is_base_of<SkillLevelDataEntry, T>::value != 0, "T must be inherited from SkillLevelDataEntry"); }
	~SkillLevelDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "playerLevel", pData->playerLevel);
			doc.GetAttribute(pDataElem, "taskId", pData->taskId);
			doc.GetAttribute(pDataElem, "needSilver", pData->needSilver);
			doc.GetAttribute(pDataElem, "needCrystal", pData->needCrystal);
			doc.GetAttribute(pDataElem, "canforget", pData->canforget);
			doc.GetAttribute(pDataElem, "forgetmoney", pData->forgetmoney);
			doc.GetAttribute(pDataElem, "needhp", pData->needhp);
			doc.GetAttribute(pDataElem, "cd", pData->cd);
			doc.GetAttribute(pDataElem, "preparetime", pData->preparetime);
			doc.GetAttribute(pDataElem, "function1", pData->function1);
			doc.GetAttribute(pDataElem, "param11", pData->param11);
			doc.GetAttribute(pDataElem, "param12", pData->param12);
			doc.GetAttribute(pDataElem, "param13", pData->param13);
			doc.GetAttribute(pDataElem, "function2", pData->function2);
			doc.GetAttribute(pDataElem, "param21", pData->param21);
			doc.GetAttribute(pDataElem, "param22", pData->param22);
			doc.GetAttribute(pDataElem, "param23", pData->param23);
			doc.GetAttribute(pDataElem, "function3", pData->function3);
			doc.GetAttribute(pDataElem, "param31", pData->param31);
			doc.GetAttribute(pDataElem, "param32", pData->param32);
			doc.GetAttribute(pDataElem, "param33", pData->param33);
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

	void VisitData(SkillLevelDataEntryVisitor<T>& visitor)
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


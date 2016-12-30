// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     SkillDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _SKILLDATALOADER_H
#define _SKILLDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct SkillDataEntry
{
	SkillDataEntry() : id(0), occu(0), usetype(0), autoLearn(0), type(0), attribute(0), distance(0), scope(0), movetype(0), radius(0), nearwidth(0), farwidth(0), targetflag(0), pkattr(0){}
	virtual ~SkillDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	技能id
	**/
	UInt16	id;

	/**
	名称
	**/
	string	name;

	/**
	职业
	**/
	UInt8	occu;

	/**
	释放方式
	**/
	UInt8	usetype;

	/**
	到达条件自动开放技能
	**/
	bool	autoLearn;

	/**
	类型
	**/
	UInt8	type;

	/**
	攻击类型
	**/
	UInt8	attribute;

	/**
	释放距离
	**/
	UInt16	distance;

	/**
	释放范围
	**/
	UInt8	scope;

	/**
	是否可以移动
	**/
	UInt8	movetype;

	/**
	伤害间隔
	**/
	string	damageinterval;

	/**
	是否调用BUFF效果
	**/
	string	buffflag;

	/**
	半径
	**/
	UInt16	radius;

	/**
	梯形近底
	**/
	UInt16	nearwidth;

	/**
	梯形远底
	**/
	UInt16	farwidth;

	/**
	目标类型
	**/
	UInt16	targetflag;

	/**
	有益或有害技能
	**/
	UInt8	pkattr;
}; // SkillDataEntry define end

//data visitor for the excel table
template <typename T>
class SkillDataEntryVisitor
{
public:
	SkillDataEntryVisitor(){ static_assert(std::is_base_of<SkillDataEntry, T>::value != 0, "T must be inherited from SkillDataEntry"); }
	virtual ~SkillDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class SkillDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	SkillDataLoader(){ static_assert(std::is_base_of<SkillDataEntry, T>::value != 0, "T must be inherited from SkillDataEntry"); }
	~SkillDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "occu", pData->occu);
			doc.GetAttribute(pDataElem, "usetype", pData->usetype);
			doc.GetAttribute(pDataElem, "autoLearn", pData->autoLearn);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "attribute", pData->attribute);
			doc.GetAttribute(pDataElem, "distance", pData->distance);
			doc.GetAttribute(pDataElem, "scope", pData->scope);
			doc.GetAttribute(pDataElem, "movetype", pData->movetype);
			doc.GetAttribute(pDataElem, "damageinterval", pData->damageinterval);
			doc.GetAttribute(pDataElem, "buffflag", pData->buffflag);
			doc.GetAttribute(pDataElem, "radius", pData->radius);
			doc.GetAttribute(pDataElem, "nearwidth", pData->nearwidth);
			doc.GetAttribute(pDataElem, "farwidth", pData->farwidth);
			doc.GetAttribute(pDataElem, "targetflag", pData->targetflag);
			doc.GetAttribute(pDataElem, "pkattr", pData->pkattr);
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

	void VisitData(SkillDataEntryVisitor<T>& visitor)
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


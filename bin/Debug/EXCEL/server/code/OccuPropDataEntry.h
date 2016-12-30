// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     OccuPropDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _OCCUPROPDATALOADER_H
#define _OCCUPROPDATALOADER_H

#include <string>
#include <vector>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct OccuPropDataEntry
{
	OccuPropDataEntry() : occu(0), type(0), hp(0), mp(0), phyatkfloor(0), phyatktop(0), magatkfloor(0), magatktop(0), def(0), hit(0), dod(0), speed(0){}
	virtual ~OccuPropDataEntry(){ }
	virtual UInt32 GetKey() const { return 0xFFFFFFFF; };
	/**
	职业
	**/
	UInt8	occu;

	/**
	属性类别
	**/
	UInt8	type;

	/**
	属性名称
	**/
	string	name;

	/**
	生命
	**/
	UInt32	hp;

	/**
	魔法
	**/
	UInt32	mp;

	/**
	物攻下限
	**/
	UInt32	phyatkfloor;

	/**
	物攻上限
	**/
	UInt32	phyatktop;

	/**
	魔攻下限
	**/
	UInt32	magatkfloor;

	/**
	魔攻上限
	**/
	UInt32	magatktop;

	/**
	防御
	**/
	UInt32	def;

	/**
	命中
	**/
	UInt32	hit;

	/**
	闪避
	**/
	UInt32	dod;

	/**
	攻击速度
	**/
	UInt32	speed;
}; // OccuPropDataEntry define end

//data visitor for the excel table
template <typename T>
class OccuPropDataEntryVisitor
{
public:
	OccuPropDataEntryVisitor(){ static_assert(std::is_base_of<OccuPropDataEntry, T>::value != 0, "T must be inherited from OccuPropDataEntry"); }
	virtual ~OccuPropDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class OccuPropDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	OccuPropDataLoader(){ static_assert(std::is_base_of<OccuPropDataEntry, T>::value != 0, "T must be inherited from OccuPropDataEntry"); }
	~OccuPropDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "occu", pData->occu);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "name", pData->name);
			doc.GetAttribute(pDataElem, "hp", pData->hp);
			doc.GetAttribute(pDataElem, "mp", pData->mp);
			doc.GetAttribute(pDataElem, "phyatkfloor", pData->phyatkfloor);
			doc.GetAttribute(pDataElem, "phyatktop", pData->phyatktop);
			doc.GetAttribute(pDataElem, "magatkfloor", pData->magatkfloor);
			doc.GetAttribute(pDataElem, "magatktop", pData->magatktop);
			doc.GetAttribute(pDataElem, "def", pData->def);
			doc.GetAttribute(pDataElem, "hit", pData->hit);
			doc.GetAttribute(pDataElem, "dod", pData->dod);
			doc.GetAttribute(pDataElem, "speed", pData->speed);
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

	void VisitData(OccuPropDataEntryVisitor<T>& visitor)
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


// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     EquipPropAddDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _EQUIPPROPADDDATALOADER_H
#define _EQUIPPROPADDDATALOADER_H

#include <string>
#include <vector>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct EquipPropAddDataEntry
{
	EquipPropAddDataEntry() : level(0), rat(0), backlevel(0), needgold(0), needmat1(0), num1(0){}
	virtual ~EquipPropAddDataEntry(){ }
	virtual UInt32 GetKey() const { return 0xFFFFFFFF; };
	/**
	追加等级
	**/
	UInt8	level;

	/**
	成功概率
	**/
	UInt16	rat;

	/**
	回退等级
	**/
	UInt8	backlevel;

	/**
	主手武器
	**/
	string	param1;

	/**
	副手武器
	**/
	string	param2;

	/**
	头盔
	**/
	string	param3;

	/**
	铠甲
	**/
	string	param4;

	/**
	护手
	**/
	string	param5;

	/**
	护腿
	**/
	string	param6;

	/**
	战靴
	**/
	string	param7;

	/**
	戒子
	**/
	string	param8;

	/**
	项链
	**/
	string	param9;

	/**
	护符
	**/
	string	param10;

	/**
	需要的银币
	**/
	UInt16	needgold;

	/**
	需要材料ID
	**/
	UInt16	needmat1;

	/**
	需要材料的数量
	**/
	UInt16	num1;
}; // EquipPropAddDataEntry define end

//data visitor for the excel table
template <typename T>
class EquipPropAddDataEntryVisitor
{
public:
	EquipPropAddDataEntryVisitor(){ static_assert(std::is_base_of<EquipPropAddDataEntry, T>::value != 0, "T must be inherited from EquipPropAddDataEntry"); }
	virtual ~EquipPropAddDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class EquipPropAddDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	EquipPropAddDataLoader(){ static_assert(std::is_base_of<EquipPropAddDataEntry, T>::value != 0, "T must be inherited from EquipPropAddDataEntry"); }
	~EquipPropAddDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "level", pData->level);
			doc.GetAttribute(pDataElem, "rat", pData->rat);
			doc.GetAttribute(pDataElem, "backlevel", pData->backlevel);
			doc.GetAttribute(pDataElem, "param1", pData->param1);
			doc.GetAttribute(pDataElem, "param2", pData->param2);
			doc.GetAttribute(pDataElem, "param3", pData->param3);
			doc.GetAttribute(pDataElem, "param4", pData->param4);
			doc.GetAttribute(pDataElem, "param5", pData->param5);
			doc.GetAttribute(pDataElem, "param6", pData->param6);
			doc.GetAttribute(pDataElem, "param7", pData->param7);
			doc.GetAttribute(pDataElem, "param8", pData->param8);
			doc.GetAttribute(pDataElem, "param9", pData->param9);
			doc.GetAttribute(pDataElem, "param10", pData->param10);
			doc.GetAttribute(pDataElem, "needgold", pData->needgold);
			doc.GetAttribute(pDataElem, "needmat1", pData->needmat1);
			doc.GetAttribute(pDataElem, "num1", pData->num1);
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

	void VisitData(EquipPropAddDataEntryVisitor<T>& visitor)
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


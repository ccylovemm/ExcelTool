// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     EquipPowerUpDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _EQUIPPOWERUPDATALOADER_H
#define _EQUIPPOWERUPDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct EquipPowerUpDataEntry
{
	EquipPowerUpDataEntry() : level(0), rat(0), backlevel(0), needgold(0), needmat1(0), num1(0), needmat2(0), num2(0), needmat3(0), num3(0), protectionid(0), protectionnum(0){}
	virtual ~EquipPowerUpDataEntry(){ }
	virtual UInt32 GetKey() const { return level; }
	/**
	强化等级
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
	string	param10;

	/**
	护身符
	**/
	string	param11;

	/**
	需要的银币
	**/
	UInt16	needgold;

	/**
	需要材料ID1
	**/
	UInt32	needmat1;

	/**
	需要材料的数量
	**/
	UInt16	num1;

	/**
	需要材料ID2
	**/
	UInt32	needmat2;

	/**
	需要材料的数量
	**/
	UInt16	num2;

	/**
	需要材料ID3
	**/
	UInt32	needmat3;

	/**
	需要材料的数量
	**/
	UInt16	num3;

	/**
	保护符ID
	**/
	UInt32	protectionid;

	/**
	需要材料的数量
	**/
	UInt16	protectionnum;
}; // EquipPowerUpDataEntry define end

//data visitor for the excel table
template <typename T>
class EquipPowerUpDataEntryVisitor
{
public:
	EquipPowerUpDataEntryVisitor(){ static_assert(std::is_base_of<EquipPowerUpDataEntry, T>::value != 0, "T must be inherited from EquipPowerUpDataEntry"); }
	virtual ~EquipPowerUpDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class EquipPowerUpDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	EquipPowerUpDataLoader(){ static_assert(std::is_base_of<EquipPowerUpDataEntry, T>::value != 0, "T must be inherited from EquipPowerUpDataEntry"); }
	~EquipPowerUpDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "param10", pData->param10);
			doc.GetAttribute(pDataElem, "param11", pData->param11);
			doc.GetAttribute(pDataElem, "needgold", pData->needgold);
			doc.GetAttribute(pDataElem, "needmat1", pData->needmat1);
			doc.GetAttribute(pDataElem, "num1", pData->num1);
			doc.GetAttribute(pDataElem, "needmat2", pData->needmat2);
			doc.GetAttribute(pDataElem, "num2", pData->num2);
			doc.GetAttribute(pDataElem, "needmat3", pData->needmat3);
			doc.GetAttribute(pDataElem, "num3", pData->num3);
			doc.GetAttribute(pDataElem, "protectionid", pData->protectionid);
			doc.GetAttribute(pDataElem, "protectionnum", pData->protectionnum);
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

	void VisitData(EquipPowerUpDataEntryVisitor<T>& visitor)
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


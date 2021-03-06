/*
			This file is part of:
				TmingEngine
			https://github.com/xiaomingfun/TmingEngine

   Copyright 2018 - 2020 TmingEngine

   File creator: littleblue

   TmingEngine is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef TmingEngine_ScriptEnginee_scheme_h
#define TmingEngine_ScriptEnginee_scheme_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

namespace TmingEngine
{
	enum class CellType
	{
		Atom, // 原子为标识符形式的符号 Symbol或数字 Number 的字面值   如果是原子，或者空表 返回t ，否则就返回 f
		Quote, // 引用，用来表示数据 ，避免被求值
		Operater, // 算术操作符
		Lambda, // 匿名函数
		Number, // 整数
		Bool,  // 布尔
		Syntax, // 语法关键词
		Nil, // 空序对
		pair, // 序对
		Symbol, // 符号
		Closure, // 闭包
		FunctionCall,//函数调用
	};

	class Pair
	{
	public:

		string Data;
		Pair* car;
		Pair* cdr;
		CellType Type;

		Pair()
		{
			Type = CellType::Nil;
			car = nullptr;
			cdr = nullptr;
		}

		operator bool()
		{
			return Data == "#t";
		}

		operator int()
		{
			int val = std::stoi(Data, nullptr, 0);
			return val;
		}

		operator float()
		{
			float val = std::stof(Data, nullptr);
			return val;
		}

		Pair(bool x)
		{
			Data = x ? "#t" : "#f";
			Type = CellType::Atom;
			car = nullptr;
			cdr = nullptr;
		}

		Pair(Pair* x)
		{
			Data = x->Data;
			Type = x->Type;
			car = x->car;
			cdr = x->cdr;
		}

		Pair(int x)
		{
			Data = std::to_string(x);
			car = nullptr;
			cdr = nullptr;
			Type = CellType::Number;
		}

		operator string()
		{
			return Data;
		}

		void InitPair(string x);

		void AutoSetType();

		Pair* eval(Pair* exp);

		void SetData(const char* x)
		{
			Data = string(x);
			AutoSetType();
		}

		void SetData(string x)
		{
			Data = x;
			AutoSetType();
		}

		Pair(const char* x)
		{
			string data = string(x);
			InitPair(data);
		}

		Pair(const char* x, Pair* y)
		{
			string data = string(x);
			InitPair(data);
			cdr = y;
		}

		Pair(const char* x, const char* y)
		{
			car = new Pair(x);
			cdr = new Pair(y);
			Type = CellType::pair;

			if (car->Type == CellType::Closure && cdr->Type == CellType::Number)
			{
				Type = CellType::FunctionCall;
			}
			else
			{
				Type = CellType::pair;
			}
		}

		Pair(Pair* _car, Pair* _cdr)
		{
			car = _car;
			cdr = _cdr;
			Type = CellType::pair;

			if (car->Type == CellType::Closure && cdr->Type == CellType::Number)
			{
				Type = CellType::FunctionCall;
			}
			else
			{
				Type = CellType::pair;
			}
		}

		Pair(Pair* _car, const char* _cdr)
		{
			car = _car;
			cdr = new Pair(_cdr);

			if (car->Type == CellType::Closure && cdr->Type == CellType::Number)
			{
				Type = CellType::FunctionCall;
			}
			else
			{
				Type = CellType::pair;
			}
		}

		Pair(string x)
		{
			InitPair(x);
		}

		bool operator ==(const Pair& other) const
		{
			if (this->Data != other.Data)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		bool operator  !=(const Pair& other)const
		{
			if (this->Data != other.Data)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		Pair* eval(Pair* exp, Pair* env);

		Pair* CaculateOperate(Pair* exp, Pair* env);

		Pair* Cons(Pair* p1, Pair* p2)
		{
			return new Pair(p1, p2);
		}

		Pair* Quote(const char* x)
		{
			Data = string(x);
			Type = CellType::Quote;
		}

		Pair* Atom(Pair* x)
		{
			if (x->Type == CellType::Symbol ||
				x->Type == CellType::Number ||
				x->Type == CellType::Nil)
			{
				Data = x->Data;
			}
		}

		Pair* ExtendEnv(Pair* p1, Pair* _env)
		{
			return Cons(p1, _env);
		}

		void ExtendEnv(Pair* p1)
		{
			Pair* oldEnv = new Pair(this);
			car = p1;
			Type = CellType::pair;
			cdr = oldEnv;
		}

		Pair* LookUp(Pair* p1, Pair* _env);

		Pair* CaculateSymbol(Pair* exp, Pair* _env);

		Pair* CaculateQuote(Pair* exp);

		Pair* CaculateSyntax(Pair* exp, Pair* env);

		Pair* CaculateLambda(Pair* exp, Pair* env);

		Pair* CaculateFucntionCall(Pair* exp, Pair* env);

		Pair* GetValueInEnv(Pair* var, Pair* env)
		{
			Pair* v;
			v = env->car;
			if (v->car == var)
			{
				return v->cdr;
			}
			else
			{
				return GetValueInEnv(var, v->cdr);
			}
		}

		void SetValueInEnv(Pair* var, Pair* env)
		{
			Pair* v = GetValueInEnv(var, env);
			if (v != nullptr)
			{
				v = var;
			}
			else
			{
				Pair* next;
				while ((next = env->cdr) != nullptr)
				{
					env = next;
				}

				env->cdr = var;
			}
		}

		void Print()
		{
			Print(this);
			std::cout << std::endl;
		}

		void Print(Pair* p)
		{
			if (p->Type != CellType::Number && p->Type != CellType::Symbol)
			{
				std::cout << "( ";
			}
			if (p->Type == CellType::Nil)
			{
				std::cout << "nil" << "";
			}
			else
			{
				std::cout << p->Data << " ";
			}

			if (p->car != nullptr)
			{
				p->Print(p->car);
			}

			if (p->cdr != nullptr)
			{
				if (p->cdr != p)
				{
					p->Print(p->cdr);
				}
			}

			if (p->Type != CellType::Number && p->Type != CellType::Symbol)
			{
				std::cout << " ) ";
			}
		}
	};

	void LoadScheme(Pair* env, string path);
}

#endif
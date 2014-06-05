package testings;

import static org.junit.Assert.*;

import java.util.regex.Matcher;

import org.junit.Test;

public class Class1Test {
	@Test
	public void test2() {
		assertEquals(100, 100);
	}
	@Test
	public void test() {
		Class2 newItem = new Class2("asd","19",4);
		String actual = newItem.returnroll("to append");
		System.out.println(actual);
		assertEquals("4to append",actual);
	}
}
